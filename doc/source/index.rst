.. dasPostgreSQL documentation master file.

dasPostgreSQL documentation
===========================

Part of the daslang ecosystem. See also the `daslang documentation
<https://daslang.io/doc/>`_ and `daslang.io <https://daslang.io>`_.

dasPostgreSQL is the daslang binding for `PostgreSQL <https://www.postgresql.org/>`_
(via libpq, the client C library) — the networked provider for daslang's
``_sql(...)`` LINQ-to-SQL machinery (``daslib/sql_linq``): declare a struct with
``[sql_table]``, and compile-time-checked query chains, typed CRUD, custom-type
adapters, ``@sql_json`` columns and transactions all work against a PostgreSQL
server exactly as they do against the in-tree SQLite provider. The shared
provider contract is documented in the daslang repo's `PROVIDER_CONTRACT.md
<https://github.com/GaijinEntertainment/daScript/blob/master/modules/dasSQLITE/PROVIDER_CONTRACT.md>`_.

**Source code**: https://github.com/borisbat/dasPostgreSQL

**Issues**: https://github.com/borisbat/dasPostgreSQL/issues

Install
=======

.. code-block:: bash

   daslang utils/daspkg/main.das -- install github.com/borisbat/dasPostgreSQL

Or add to your project's ``.das_package``:

.. code-block:: das

   [export]
   def dependencies(version : string) {
       require_package("github.com/borisbat/dasPostgreSQL")
   }

Then run ``daspkg install``.

Quick taste
===========

.. code-block:: das

   require postgres/postgres_boost
   require daslib/sql_linq

   [sql_table(name = "Users")]
   struct User {
       @sql_primary_key Id : int64
       Name : string
       Age : int
   }

   [export]
   def main {
       with_postgres("host=localhost dbname=mydb user=me") $(db) {
           db |> create_table(type<User>)
           db |> insert(User(Id = int64(0), Name = "Ada", Age = 36))
           let adults = _sql(db |> select_from(type<User>) |> _where(_.Age >= 18))
       }
   }

.. toctree::
   :maxdepth: 2
   :caption: Contents

   stdlib/index
