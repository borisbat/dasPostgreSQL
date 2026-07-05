.. _stdlib_postgres_external_types_section:

**************
External types
**************

Types referenced by the generated module pages but owned elsewhere — the
``postgres_stmt`` statement module, the raw ``postgres`` libpq binding, and
daslang's ``daslib/sql`` core. This page anchors their labels so the generated
pages link without dangling references; follow the upstream links for the
authoritative definitions. (Daslang-core types such as ``Result`` / ``Option``
resolve against the `daslang documentation <https://daslang.io/doc/>`_ via
intersphinx.)

.. _struct-postgres_stmt-pgstmt:

``postgres_stmt::PgStmt``
=========================

The provider statement handle spliced into ``_sql``-emitted bind/reader blocks.
libpq has no per-index bind API — ``PQexecParams`` takes the whole parameter set
at execute time — so the handle accumulates three parallel arrays (text-format
value, NULL flag, explicit type OID) during the bind block, then carries the
executed ``PGresult`` and the current row for the readers. User code never
constructs one; the ``run_select`` family owns its lifecycle.

.. _alias-pgconn:

``postgres::PGconn``
====================

The raw libpq connection handle (`libpq documentation
<https://www.postgresql.org/docs/current/libpq-connect.html>`_), owned by
``SqlRunner`` and passed to ``PQ*`` functions when dropping below the boost
layer.

.. _alias-pgresult:

``postgres::PGresult``
======================

The raw libpq result handle (`libpq exec documentation
<https://www.postgresql.org/docs/current/libpq-exec.html>`_) — a fully
materialized query result read by (row, column). Owned by the runner helpers;
``PgStmt.res`` points at one while rows are read.

.. _enum-sql-sqltype:

``sql::SqlType``
================

Daslang's abstract SQL storage class (``Integer`` / ``Real`` / ``Text`` /
``Blob`` / ``Null``, from ``daslib/sql``). The provider renders it to PostgreSQL
spellings via ``postgres_sql_type`` — ``BIGINT`` / ``DOUBLE PRECISION`` /
``TEXT`` / ``BYTEA``.

.. _alias-sqlerror:

``sql::SqlError``
=================

``Option<string>`` from ``daslib/sql`` — ``none`` on success, ``some(errmsg)``
on failure. The return type of every ``try_*`` helper that has no payload.
