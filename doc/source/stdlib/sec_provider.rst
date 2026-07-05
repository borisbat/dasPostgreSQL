.. _stdlib_postgres_provider_section:

******************************************
postgres_provider — the registration shim
******************************************

The lean bridge between the raw ``postgres`` libpq binding and the neutral
provider registry in ``daslib/sql_provider``: statement-type factories, dialect
hooks (placeholder renumbering, ``jsonb_path_query_first`` descent, type
spellings), capability flags, and the schema readers behind ``check_schema``
and ``[sql_table(schema_from=...)]``.

.. toctree::

   generated/postgres_provider.rst
