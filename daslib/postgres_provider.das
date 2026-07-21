options gen2
options _comment_hygiene = true
options indenting = 4
options no_unused_function_arguments = false
options strict_smart_pointers

module postgres_provider shared public

require postgres
require postgres/postgres_stmt public
require strings
require daslib/sql public
require daslib/sql_provider public
require daslib/ast_boost
require daslib/templates
require daslib/templates_boost

//! PostgreSQL's `SqlProviderInfo` registration shim — the lean bridge between the raw
//! `postgres` libpq binding and the neutral registry in `daslib/sql_provider`.
//! Deliberately does NOT require `postgres/postgres_boost`: `daslib/sql_boost` pulls
//! this file into every consulting macro context via `require ?postgres`, and requiring
//! the boost here would cycle. Runtime surface (SqlRunner, exec/query, runner helpers)
//! lives in `postgres/postgres_boost`.

def postgres_sql_type(t : SqlType) : string {
    //! Render an abstract ``SqlType`` to its PostgreSQL-dialect spelling. `Integer` is
    //! ``BIGINT`` — PG types are strict (no SQLite affinity), and das `int64` must fit.
    if (t == SqlType.Integer) return "BIGINT"
    if (t == SqlType.Real) return "DOUBLE PRECISION"
    if (t == SqlType.Text) return "TEXT"
    if (t == SqlType.Blob) return "BYTEA"
    return "NULL"
}

def postgres_decl_to_sql_type(decl_type : string) : SqlType {
    //! Normalize a PostgreSQL declared column type (``format_type`` spelling) to the
    //! abstract storage class. Strict-typed: exact families, no affinity rules.
    let upper = decl_type |> to_upper
    if (find(upper, "INT") >= 0 || upper == "BOOLEAN" || upper == "BOOL") return SqlType.Integer
    if (find(upper, "DOUBLE") >= 0 || find(upper, "REAL") >= 0 || find(upper, "NUMERIC") >= 0 || find(upper, "DECIMAL") >= 0 || find(upper, "FLOAT") >= 0) return SqlType.Real
    if (find(upper, "CHAR") >= 0 || find(upper, "TEXT") >= 0) return SqlType.Text
    if (find(upper, "BYTEA") >= 0) return SqlType.Blob
    return SqlType.Text
}

def private _pg_text_cell(res : PGresult?; row, col : int) : string {
    // context-heap copy of a result cell (PQgetvalue memory dies with the PGresult)
    return clone_string(PQgetvalue(res, row, col))
}

def postgres_read_table_info(conn : PGconn?; schema_name : string; tbl_name : string) : Result<array<SchemaFromCol>, string> {
    //! pg_catalog introspection → normalized column metadata. `schema_name` qualifies
    //! the lookup; empty means the connection's current schema (search_path head).
    var rows : array<SchemaFromCol>
    let schema_pred = empty(schema_name) ? "n.nspname = current_schema()" : "n.nspname = {sql_quote_lit(schema_name)}"
    let sql = ("SELECT a.attname, format_type(a.atttypid, a.atttypmod), a.attnotnull, COALESCE(i.indisprimary, false) "
        + "FROM pg_attribute a "
        + "JOIN pg_class c ON c.oid = a.attrelid "
        + "JOIN pg_namespace n ON n.oid = c.relnamespace "
        + "LEFT JOIN pg_index i ON i.indrelid = a.attrelid AND a.attnum = ANY(i.indkey) AND i.indisprimary "
        + "WHERE c.relname = {sql_quote_lit(tbl_name)} AND {schema_pred} AND a.attnum > 0 AND NOT a.attisdropped "
        + "ORDER BY a.attnum")
    var res = PQexec(conn, sql)
    if (PQresultStatus(res) != ExecStatusType.PGRES_TUPLES_OK) {
        let msg = "table_info({tbl_name}) failed: {clone_string(PQresultErrorMessage(res))}"
        PQclear(res)
        return err(msg, type<array<SchemaFromCol>>)
    }
    let n = PQntuples(res)
    rows |> reserve(n)
    for (i in range(n)) {
        let dt = _pg_text_cell(res, i, 1)
        rows |> emplace(SchemaFromCol(
            name = _pg_text_cell(res, i, 0),
            decl_type = dt,
            data_type = postgres_decl_to_sql_type(dt),
            not_null = _pg_text_cell(res, i, 2) == "t",
            pk = _pg_text_cell(res, i, 3) == "t"
        ))
    }
    PQclear(res)
    return <- move_ok(rows, type<string>)
}

def private _postgres_read_table_schema(path : string; tbl_name : string) : Result<array<SchemaFromCol>, string> {
    // `path` is a libpq conninfo string ("host=... dbname=..." or postgres:// URL)
    var conn = PQconnectdb(path)
    if (conn == null || PQstatus(conn) != ConnStatusType.CONNECTION_OK) {
        let msg = "PQconnectdb(\"{path}\") failed: {clone_string(PQerrorMessage(conn))}"
        PQfinish(conn)
        return err(msg, type<array<SchemaFromCol>>)
    }
    var r <- postgres_read_table_info(conn, "", tbl_name)
    PQfinish(conn)
    return <- r
}

def private _postgres_make_stmt_type() : TypeDeclPtr => qmacro_type(type<PgStmt?>)

// Both flavors splice the SAME mutable type: das const-ness flows through field
// access, and the readers must reach `res`/`row` through the handle — so the
// reader-block parameter stays mutable (the runner helpers declare it `var` to match).
def private _postgres_make_stmt_type_const() : TypeDeclPtr => qmacro_type(type<PgStmt?>)

// "?" like the SQLite reference: every SQL string carries `?` markers whose text order IS the
// bind-index order; postgres_boost renumbers them to $1,$2,... in one quote-aware pass right
// before PQexecParams (libpq accepts only the $n style).
[unused_argument(ordinal)]
def private _postgres_render_placeholder(ordinal : int) : string => "?"

// jsonb_path_query_first takes the same '$.a.b' literal the macro renders, and `#>> '{}'` unwraps
// the jsonb scalar to unquoted text — matching SQLite's unquoted-scalar json_extract semantics
// for predicate/projection descent.
def private _postgres_render_json_extract(target : string; jsonPath : string) : string => "(jsonb_path_query_first(({target})::jsonb, {jsonPath}::jsonpath) #>> '\{\}')"

def private _postgres_quote_id(id : string) : string => sql_quote_id(id)

def register_postgres_provider {
    //! Registers the postgres `SqlProviderInfo` entry in the CURRENT macro context.
    //! Reached via `sql_register_present_providers` (daslib/sql_boost) from each
    //! consulting macro module's own `[_macro]`.
    var info = SqlProviderInfo(
        name = "postgres",
        runnerModule = "postgres_boost",
        runnerStruct = "SqlRunner",
        makeStmtType = @@_postgres_make_stmt_type,
        makeStmtTypeConst = @@_postgres_make_stmt_type_const,
        renderPlaceholder = @@_postgres_render_placeholder,
        noLimitSpelling = "",
        renderJsonExtract = @@_postgres_render_json_extract,
        quoteId = @@_postgres_quote_id,
        sqlTypeFor = @@postgres_sql_type,
        identityDdl = "GENERATED BY DEFAULT AS IDENTITY PRIMARY KEY",
        readTableSchema = @@_postgres_read_table_schema,
        caps = SqlProviderCaps.returning | SqlProviderCaps.distinct_on,
        pkReport = SqlPkReport.ReturningPk)
    register_sql_provider(info)
}
