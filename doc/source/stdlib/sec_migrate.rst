.. _stdlib_postgres_migrate_section:

************************************************
postgres_migrate — versioned schema migrations
************************************************

PostgreSQL glue for the provider-neutral migrations engine (``daslib/sql_migrate``
in the daslang repo, re-exported here): ``[sql_migration]``,
``migrate_to_latest`` / ``try_migrate_to_latest``, ``baseline``,
``[struct_convert]`` and ``convert_and_rename`` all work through this module.
Concurrent migrators coordinate on a session advisory lock keyed on the current
database: the strict forms block until the lock frees (session locks
auto-release when their holder crashes or disconnects), while the ``try_``
siblings fail fast.

.. toctree::

   generated/postgres_migrate.rst
