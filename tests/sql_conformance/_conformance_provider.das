options gen2
options indenting = 4

module _conformance_provider shared public

//! SQL-provider conformance shim — the ONE file a provider swaps to run the shared
//! suite (see README.md). PostgreSQL edition: one shared server (``DAS_PG_CONNINFO``
//! or the local dev default below), an isolated throwaway schema per call, dropped
//! CASCADE on scope exit. ``test_conf_fts5.das`` and ``test_conf_sql_functions.das``
//! are dropped from this copy (caps.fts5 and caps.client_udfs are both off — PG has
//! neither FTS5 nor client-side UDFs; see the README's capability-skip policy).

// The migration glue is required before the boost — mirrors the main-repo shim, where
// requiring the boost first can resurrect a stale shared-module generation after
// intentionally-failing compile tests in the same dastest process (daslang
// shared-module promotion bug; see the main repo's shim for the minimal repro).
require postgres
require postgres/postgres_migrate public
require postgres/postgres_boost public
require daslib/sql_linq public
require daslib/fio

// Capability constants — mirror the provider's SqlProviderCaps registry entry.
let public CONF_PROVIDER_NAME = "postgres"
let public CONF_HAS_FTS5 = false
let public CONF_HAS_CLIENT_UDFS = false
let public CONF_HAS_RETURNING = true

var private g_conf_seq = 0

def private conf_conninfo : string {
    if (has_env_variable("DAS_PG_CONNINFO")) return get_env_variable("DAS_PG_CONNINFO")
    return "host=localhost port=5499 user=postgres dbname=postgres"
}

[unused_argument(e)]
def private ignore_conf_error(e : SqlError) : void {
}

def public with_conf_db(blk : block<(db : SqlRunner) : void>) : void {
    //! Scoped fresh empty database — every conformance test runs against one of these.
    //! A test panic skips the ``finally`` cleanup by design (the schema leaks on the
    //! shared server until the next run of the same test recreates it).
    var inscope db = open_postgres(conf_conninfo())
    g_conf_seq++
    let schema = "conf_{PQbackendPID(db.conn)}_{g_conf_seq}"
    db |> exec("DROP SCHEMA IF EXISTS {sql_quote_id(schema)} CASCADE")
    db |> exec("CREATE SCHEMA {sql_quote_id(schema)}")
    db |> exec("SET search_path TO {sql_quote_id(schema)}")
    {
        invoke(blk, db)
    } finally {
        db |> try_exec("DROP SCHEMA {sql_quote_id(schema)} CASCADE") |> ignore_conf_error
    }
}
