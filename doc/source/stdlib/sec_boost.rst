.. _stdlib_postgres_boost_section:

***********************************
postgres_boost — the runtime layer
***********************************

The runtime surface user code touches: the ``SqlRunner`` connection owner and its
RAII helpers, raw ``exec`` / ``try_exec``, typed CRUD over ``[sql_table]`` structs,
transactions, and the ``run_select`` family the ``_sql(...)`` macros emit against.

.. toctree::

   generated/postgres_boost.rst
