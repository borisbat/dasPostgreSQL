.. _stdlib:

#################
  dasPostgreSQL
#################

The dasPostgreSQL surface, organised by area: the runtime boost (runner, raw SQL,
typed CRUD, the ``_sql`` runtime helpers), the provider registration shim, and
the migrations glue. The underlying ``PQ*`` libpq bindings are not duplicated
here — they mirror
`libpq's C API <https://www.postgresql.org/docs/current/libpq.html>`_ one-to-one.

.. toctree::
   :maxdepth: 3
   :numbered:

   sec_boost.rst
   sec_provider.rst
   sec_migrate.rst
   external_types.rst
