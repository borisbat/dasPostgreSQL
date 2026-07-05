PostgreSQL glue for the provider-neutral migrations engine
(``daslib/sql_migrate`` in the daslang repo, re-exported here, so one
``require postgres/postgres_migrate`` covers the whole surface):
``[sql_migration]`` declares a versioned migration whose runner parameter type
routes it into PostgreSQL's stream (versions are unique per provider stream),
``migrate_to_latest`` / ``try_migrate_to_latest`` apply whatever is pending
inside one transaction, ``baseline`` adopts pre-existing databases, and
``[struct_convert]`` + ``convert_and_rename`` rebuild tables across shape
changes.

The glue supplies the engine's per-provider hooks (see PROVIDER_CONTRACT.md
§Migrations in the daslang repo). Concurrent migrators coordinate on a SESSION
advisory lock keyed on the current database (classid ``0x0da51a09`` +
``hashtext(current_database())``): the strict forms take ``pg_advisory_lock``
and block until a concurrent migrator finishes — session locks auto-release
when their holder crashes or disconnects, so there is no stuck-lock failure
mode — while the ``try_`` siblings use ``pg_try_advisory_lock`` and fail fast.
The lock is taken before ``BEGIN`` and released after COMMIT/ROLLBACK; running
inside an ambient transaction is refused (the migration COMMIT would commit the
caller's open work too). Catalog probes go through ``information_schema``
scoped to ``current_schema()``; the audit table's ``applied_at`` is stamped
client-side (epoch seconds), keeping the engine's SQL portable.
