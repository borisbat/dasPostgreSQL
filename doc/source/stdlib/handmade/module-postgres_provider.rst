PostgreSQL's entry in the neutral SQL provider registry (``daslib/sql_provider``)
— the compile-time half of the provider. ``register_postgres_provider`` is
called by ``sql_register_present_providers`` (from ``daslib/sql_boost``) in
every macro context that analyzes ``_sql`` chains; the entry carries the
``PgStmt?`` statement-type factories the macros splice into emitted bind/reader
blocks, the dialect hooks (``?`` placeholders — renumbered to ``$n`` by the
boost's execute path; ``jsonb_path_query_first(...) #>> '{}'`` for ``@sql_json``
descent, matching SQLite's unquoted-scalar semantics; and the ``BIGINT`` /
``DOUBLE PRECISION`` / ``TEXT`` / ``BYTEA`` type spellings), and the capability
flags (RETURNING on; FTS5 and client UDFs off — PostgreSQL runs no client code,
and its full-text search is a different surface).

The runtime helpers here (``postgres_read_table_info`` over ``pg_catalog``, the
conninfo-based ``schema_from`` reader, ``postgres_sql_type`` /
``postgres_decl_to_sql_type``) back ``check_schema`` and
``[sql_table(schema_from=...)]``. This module deliberately does not require
``postgres/postgres_boost`` — that would cycle through ``daslib/sql_boost``.
