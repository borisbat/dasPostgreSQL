options gen2
require cbind/cbind_boost
require daslib/fio
require daslib/defer
require daslib/strings_boost
require daslib/functional

// Binding generator for libpq (the PostgreSQL client C API) — mirrors
// dasDuckDB's bind_duckdb.das. Parses pgsql/include/libpq-fe.h (from the EDB
// binaries package, downloaded by CMake configure) via libclang and emits the
// committed C++ binding (src/dasPOSTGRESQL.*).
// Run FROM THE REPO ROOT: daslang bind/bind_postgres.das
// (needs a daslang build with dasClangBind enabled; see the daslang repo's
// skills/clang_bind_build.md)

class PostgresGen : CppGenBind {
    override func_to_stdout = false
    override include_local_parse_file = true
    override generate_constant_decl = true

    pq_c_headers <- array<string>(
        "libpq-fe.h"
    )

    def PostgresGen {
        bind_root = get_full_file_name("src")
        bind_module = "dasPOSTGRESQL"
        bind_das_module = "postgres"
        let pfn = "cb_dasPOSTGRESQL.h"
        let pfp = "{get_full_file_name("src")}/"
        let pq_i = "{get_full_file_name("pgsql/include")}/"
        CONST_FILE_NAMES <- array<string>(
            "{pq_i}libpq-fe.h"
        )
        let args <- array<string>(
            // C++ mode, not C: matches bind_duckdb — C-mode libclang spells bool
            // as `_Bool` which leaks into generated code and breaks MSVC.
            "-xc++-header",
            "-std=c++17",
            "-I{pfp}",
            "-I{pq_i}"
        )
        func_per_chunk = 20
        super(pfn, pfp, args)
        openAllFiles()
        for (h in pq_c_headers) {
            h = to_upper(h)
        }
    }
    def override open_file_name : string {
        return "{PARSE_FILE_PREFIX}{PARSE_FILE_NAME}"
    }
    def override isArgByValue(name : string) {
        return true
    }
    def override skip_file(fname : string) : bool {
        let ufname = to_upper(fname)
        return !any <| [iterator for(h in pq_c_headers); ufname |> ends_with(h)]
    }
    def override skip_alias(var c : CXCursor) {
        let tdn = string(clang_getCursorDisplayName(c))
        var tdt = clang_getCanonicalType(clang_getCursorType(c))
        let tdts = string(clang_getTypeSpelling(tdt))
        if ("struct {tdn}" == tdts) {
            return true
        }
        let aliasf = to_upper(clang_getCursorLocationFileName(c))
        return !any <| [iterator for(h in pq_c_headers); aliasf |> ends_with(h)]
    }
    def override skip_enum(ns_en, en : string) {
        return false
    }
    def override skip_struct(sn : string) {
        // pgNotify / PQconninfoOption / PQprintOpt / pgresAttDesc back functions we
        // skip below (struct-array returns, FILE* printers, PQsetResultAttrs);
        // PQArgBlock (PQfn) carries an anonymous union.
        return (sn |> starts_with("__crt")
            || sn == "pgNotify" || sn == "PGnotify"
            || sn == "_PQconninfoOption" || sn == "PQconninfoOption"
            || sn == "_PQprintOpt" || sn == "PQprintOpt"
            || sn == "pgresAttDesc" || sn == "PGresAttDesc"
            || sn == "PQArgBlock"
            || (sn |> find("(unnamed") >= 0))
    }
    def override skip_function(var c : CXCursor) : bool {
        let fname = string(clang_getCursorSpelling(c))
        // size_t / pg_int64 / pg_usec_time_t carriers: the binder canonicalizes those
        // to `unsigned long long`/`long long`, which is a DIFFERENT type from LP64
        // Linux's `unsigned long`-flavored uint64_t — the generated makeExtern then
        // fails under gcc (same trap as dasDuckDB's duckdb_validity_* skip).
        if (fname |> starts_with("PQescape") || fname == "PQunescapeBytea" || fname == "PQresultMemorySize"
                || fname == "PQsocketPoll" || fname == "PQgetCurrentTimeUSec"
                // large objects (also pg_int64 carriers in the 64-bit forms)
                || fname |> starts_with("lo_")
                // FILE* printers/tracers
                || fname == "PQtrace" || fname == "PQuntrace" || fname == "PQprint" || fname == "PQdisplayTuples" || fname == "PQprintTuples"
                // struct-array returns (PQconninfoOption*) + PGnotify* + PGresAttDesc consumers
                || fname == "PQconndefaults" || fname == "PQconninfo" || fname == "PQconninfoParse" || fname == "PQconninfoFree"
                || fname == "PQnotifies" || fname == "PQfreeNotify" || fname == "PQsetResultAttrs" || fname == "PQfn"
                // SSL introspection returning void* / library-internal structs
                || fname == "PQgetssl" || fname == "PQsslStruct") {
            return true
        }
        let funf = to_upper(clang_getCursorLocationFileName(c))
        return !any <| [iterator for(h in pq_c_headers); funf |> ends_with(h)] || skip_anyFunction(c, false)
    }
}

[export]
def main {
    // generate
    var cgb = new PostgresGen()
    defer() {
        unsafe {
            delete cgb
        }
    }
    cgb->generate()
    cgb->genCMakeDecl("DAS_POSTGRESQL")
}
