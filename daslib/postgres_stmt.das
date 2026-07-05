options gen2
options indenting = 4
options no_unused_function_arguments = false
options strict_smart_pointers

module postgres_stmt shared public

require postgres

//! The provider statement handle spliced into `_sql`-emitted bind/reader blocks —
//! accumulated parameters plus a cursor over the executed result. Lives in its own
//! leaf module (below both `postgres/postgres_boost` and `postgres/postgres_provider`)
//! because the registration shim needs `type<PgStmt?>` but must not require the boost
//! (that cycles through `daslib/sql_boost`).
//!
//! libpq has no per-index bind API — `PQexecParams` takes the whole parameter set as
//! C arrays at execute time. So "binding" fills three parallel arrays (text-format
//! value, NULL flag, explicit type OID), and the runner helper passes them to the
//! `pq_exec_params` trampoline in one shot. Results are materialized `PGresult`s
//! read by (row, col) — the handle carries the result pointer and the current row.

struct public PgStmt {
    params : array<string>      //!< text-format parameter values, slot i = placeholder $i+1
    nulls : array<uint8>        //!< 1 = send SQL NULL for this slot
    oids : array<uint>          //!< explicit parameter type OID (0 = let the server infer)
    res : PGresult?             //!< points at the runner helper's result while rows are read
    row : int                   //!< current row for the (row, col) value readers
}
