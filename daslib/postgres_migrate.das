options gen2
options indenting = 4
options no_unused_block_arguments = false
options no_unused_function_arguments = false
options strict_smart_pointers

module postgres_migrate shared public

// Intentionally opt in for user-facing docs: keep comments concise and actionable.
options _comment_hygiene = true

require postgres_boost public
require daslib/sql_migrate public

require strings public
require daslib/option public

//! PostgreSQL glue for the provider-neutral migrations engine (``daslib/sql_migrate``,
//! re-exported here — ``[sql_migration]``, ``migrate_to_latest``, ``baseline``,
//! ``[struct_convert]``, ``convert`` / ``convert_and_rename`` all work via this module).
//! Concurrent migrators coordinate on a SESSION advisory lock keyed on the current
//! database: ``migrate_to_latest`` / ``baseline`` BLOCK until the lock frees (a session
//! lock auto-releases when its holder crashes or disconnects — no stuck-lock failure
//! mode), while the ``try_`` siblings fail fast. Contract: PROVIDER_CONTRACT.md
//! §Migrations (daslang repo, modules/dasSQLITE).

// classid half of the two-int advisory lock key — identifies "daslang sql_migrate"
// traffic; the objid half is hashtext(current_database()).
let private PG_MIGRATION_LOCK_CLASSID = 0x0da51a09

[unused_argument(e)]
def private _swallow(e : SqlError) : void {
    // best-effort unlock/cleanup — the original failure must reach the caller intact
}

// ===== Migration glue hooks (see PROVIDER_CONTRACT.md §Migrations) =====

[unused_argument(db)]
def _migration_stream_key(db : SqlRunner) : string {
    //! Stream identity for PostgreSQL migrations — must spell ``<runnerModule>::<RunnerStruct>``
    //! exactly as the provider registry keys the runner.
    return "postgres_boost::SqlRunner"
}

def _migration_begin(db : SqlRunner; blocking : bool) : SqlError {
    //! Session advisory lock (blocking waits, non-blocking fails fast), then ``BEGIN``.
    //! Refuses inside an ambient transaction: the engine's COMMIT would otherwise
    //! commit the caller's open work along with the migrations.
    if (db |> in_transaction) {
        return some("migrate_to_latest/baseline cannot run inside an open transaction — the migration COMMIT would commit the ambient work too")
    }
    if (blocking) {
        let lock_err = db |> try_exec("SELECT pg_advisory_lock({PG_MIGRATION_LOCK_CLASSID}, hashtext(current_database()))")
        if (lock_err |> is_some) return lock_err
    } else {
        let got <- db |> _migration_query_int("SELECT CASE WHEN pg_try_advisory_lock({PG_MIGRATION_LOCK_CLASSID}, hashtext(current_database())) THEN 1 ELSE 0 END")
        if (got |> is_err) return some(got |> unwrap_err)
        if ((got |> unwrap) == 0) {
            return some("another migrator holds the migration advisory lock — try_ variants fail fast; migrate_to_latest/baseline block instead")
        }
    }
    let begin_err = db |> try_exec("BEGIN")
    if (begin_err |> is_some) {
        db |> try_exec("SELECT pg_advisory_unlock({PG_MIGRATION_LOCK_CLASSID}, hashtext(current_database()))") |> _swallow
    }
    return begin_err
}

def _migration_end(db : SqlRunner) : void {
    //! Releases the session advisory lock after COMMIT/ROLLBACK.
    db |> try_exec("SELECT pg_advisory_unlock({PG_MIGRATION_LOCK_CLASSID}, hashtext(current_database()))") |> _swallow
}

def _migration_query_int(db : SqlRunner; sql : string) : Result<int, string> {
    //! One-int-result query rail for the engine's COUNT/MAX probes.
    return <- try_run_select_one(db, sql,
        $(var _stmt : PgStmt?) {},
        $(var stmt : PgStmt?) {
            return read_via_adapter(stmt, 0, type<int>)
        })
}

def _migration_audit_exists(db : SqlRunner) : Result<bool, string> {
    //! Catalog probe for ``__schema_version`` via information_schema, scoped to the
    //! session's current schema (conformance runs use a throwaway schema per test).
    let r <- db |> _migration_query_int(
        "SELECT COUNT(*) FROM information_schema.tables WHERE table_schema = current_schema() AND table_name = '__schema_version'")
    if (r |> is_err) return err(r |> unwrap_err, type<bool>)
    return ok((r |> unwrap) > 0, type<string>)
}

def _migration_has_user_objects(db : SqlRunner) : bool {
    //! True when the current schema already has user tables/views — drives the engine's
    //! adoption hint. Query failure counts as "no objects".
    let r <- db |> _migration_query_int(
        "SELECT COUNT(*) FROM information_schema.tables WHERE table_schema = current_schema() AND table_name != '__schema_version'")
    return (r |> is_ok) && (r |> unwrap) > 0
}

def _migration_history_rows(db : SqlRunner) : Result<array<MigrationRecord>, string> {
    //! Reads every ``__schema_version`` row via the native statement rail.
    return <- try_run_select(db,
        "SELECT version, description, applied_at FROM __schema_version ORDER BY version",
        $(var _stmt : PgStmt?) {},
        $(var stmt : PgStmt?) {
            return MigrationRecord(
                version = read_via_adapter(stmt, 0, type<int>),
                description = read_via_adapter(stmt, 1, type<string>),
                applied_at = read_via_adapter(stmt, 2, type<int64>))
        })
}

def _migration_invoke_body(db : SqlRunner; body : MigrationBodyCarrier) : void {
    //! Re-types the erased registry entry back to this provider's body signature and runs it.
    let typed = unsafe(reinterpret<function<(db : SqlRunner) : void>>(body))
    invoke(typed, db)
}

// ===== with_latest_postgres — convenience wrapper =====

def with_latest_postgres(conninfo : string; blk : block<(db : SqlRunner) : void>) : void {
    //! Combines ``with_postgres(conninfo)`` + ``migrate_to_latest`` — the preferred
    //! app-startup form when migrations are in play.
    with_postgres(conninfo) $(db) {
        db |> migrate_to_latest()
        invoke(blk, db)
    }
}
