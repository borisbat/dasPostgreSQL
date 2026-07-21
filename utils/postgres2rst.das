options gen2
options _comment_hygiene = true
options rtti = true

require daslib/fio
require daslib/rtti
require daslib/ast
require daslib/rst_comment
require daslib/rst
require daslib/regex
require daslib/regex_boost
require daslib/profiler_boost

// Pull in every documented module so RTTI can see them. The raw `postgres`
// libpq binding is intentionally excluded — it mirrors libpq one-to-one and is
// documented upstream; `postgres_stmt` (the PgStmt handle struct) is covered
// prose-side in the boost intro.
require postgres/postgres_boost
require postgres/postgres_provider
require postgres/postgres_migrate

def document_module_postgres_boost() {
    var mod = find_module("postgres_boost")
    var groups <- array<DocGroup>(
        group_by_regex("Runner & lifecycle", mod, %regex~^(try_open_postgres|open_postgres|with_postgres|finalize|libpq_version|postgres_server_version|in_transaction)$%%),
        group_by_regex("Raw SQL", mod, %regex~^(exec|try_exec|renumber_placeholders)$%%),
        group_by_regex("CRUD over [sql_table] structs", mod, %regex~^(try_)?(create_table|drop_table_if_exists|drop_view_if_exists|check_schema|insert|update|delete_|delete_by_id|select_from)$%%),
        group_by_regex("Transactions", mod, %regex~^(with_transaction|try_transaction)$%%),
        group_by_regex("_sql runtime helpers", mod, %regex~^(try_)?run_(select|select_one|select_one_opt|each_select|dml|dml_returning)$%%),
        group_by_regex("Storage-class bridge", mod, %regex~^(sql_bind_to_stmt|sql_read_witness|read_via_adapter)$%%),
        hide_group(group_by_regex("Internal", mod, %regex~^(_|priv_|pg_|build_postgres_|ignore_sql_|txn_).*%%))
    )
    document("postgres_boost — runner, CRUD, transactions, _sql runtime", mod, "postgres_boost.rst", groups)
}

def document_module_postgres_provider() {
    var mod = find_module("postgres_provider")
    var groups <- array<DocGroup>(
        group_by_regex("Registration", mod, %regex~^register_postgres_provider$%%),
        group_by_regex("Dialect helpers", mod, %regex~^(postgres_sql_type|postgres_decl_to_sql_type)$%%),
        group_by_regex("Schema introspection", mod, %regex~^postgres_read_table_info$%%),
        hide_group(group_by_regex("Internal", mod, %regex~^(_|priv_).*%%))
    )
    document("postgres_provider — SqlProviderInfo registration shim", mod, "postgres_provider.rst", groups)
}

def document_module_postgres_migrate() {
    var mod = find_module("postgres_migrate")
    var groups <- array<DocGroup>(
        group_by_regex("Convenience", mod, %regex~^with_latest_postgres$%%),
        hide_group(group_by_regex("Engine glue hooks (see PROVIDER_CONTRACT §Migrations)", mod, %regex~^(_migration_|_swallow).*%%))
    )
    document("postgres_migrate — migrations glue over daslib/sql_migrate", mod, "postgres_migrate.rst", groups)
}

// dasPostgreSQL repo root, derived from a loaded module's own source path so docs
// generate correctly under both -load_module (dev) and daspkg-install (CI),
// without assuming the package lives under <das_root>/modules/.
def daspostgresql_root() : string {
    let m = find_module("postgres_boost")
    assert(m != null, "postgres_boost not loaded — cannot locate dasPostgreSQL root")
    return dir_name(dir_name(string(m.fileName)))
}

[export]
def main {
    disable_profiler(this_context())
    disable_profiler_log(this_context())
    ast_gc_guard() {
        let doc_root = daspostgresql_root() + "/doc/source/stdlib"
        topic_root = "{doc_root}/generated"
        handmade_root = doc_root

        document_module_postgres_boost()
        document_module_postgres_provider()
        document_module_postgres_migrate()
    }
}
