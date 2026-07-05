# dasPostgreSQL

[PostgreSQL](https://www.postgresql.org/) bindings for the
[daslang](https://daslang.io/) programming language — a libpq-based client,
usable from daslang scripts, including as the networked provider for the
`_sql(...)` LINQ-to-SQL machinery in `daslib/sql_linq`.

Sibling project to the in-tree `dasSQLITE` module (the reference SQL provider)
and [dasDuckDB](https://github.com/borisbat/dasDuckDB) (the embedded analytical
provider); the provider contract all three implement is documented in
[PROVIDER_CONTRACT.md](https://github.com/GaijinEntertainment/daScript/blob/master/modules/dasSQLITE/PROVIDER_CONTRACT.md).

**Documentation**: https://borisbat.github.io/dasPostgreSQL/

## Versions

- **libpq 18.x** — on Windows the client pieces come from the pinned EDB
  binaries package, downloaded at CMake configure time (pinned URL + SHA256);
  on Linux/macOS the system package is used (`apt install libpq-dev`,
  `brew install libpq`). Any PostgreSQL server ≥ 12 should work (identity
  columns, `jsonb_path_query_first`).

## Requirements

- daslang SDK (with dynamic-module support)
- CMake 3.18+, a C++17 compiler (MSVC / GCC / Clang)
- a PostgreSQL server to talk to

## Build

Via daspkg:

```
daspkg install github.com/borisbat/dasPostgreSQL
```

Or configure the native module directly:

```
cmake -B build -DDASLANG_DIR=/path/to/daslang
cmake --build build --config Release
```

This produces `dasModulePostgreSQL.shared_module` in the repo root, which
`.das_module` registers for the dynamic daslang binary. On Windows the libpq
runtime DLLs are copied beside it; on POSIX the system libpq resolves at
runtime.

On macOS, brew's libpq is keg-only — point CMake at it:

```
cmake -B build -DDASLANG_DIR=/path/to/daslang -DPostgreSQL_ROOT=$(brew --prefix libpq)
```

## Modules

| Module | Require | Role |
|---|---|---|
| `postgres` | `require postgres` | raw libpq binding (generated from `libpq-fe.h`) |
| `postgres_boost` | `require postgres/postgres_boost` | runner (`SqlRunner`), `with_postgres`, exec/query surface, `_sql` runtime helpers |
| `postgres_provider` | `require postgres/postgres_provider` | lean registration shim for the `daslib/sql_provider` registry |

## Local development

Run/lint/test against a daslang checkout without installing:

```
daslang -load_module /path/to/dasPostgreSQL your_script.das
```

The conformance suite (`tests/sql_conformance/`) needs a live server; it reads
`DAS_PG_CONNINFO` (defaulting to `host=localhost port=5499 user=postgres
dbname=postgres`) and isolates every test in a throwaway schema.

## Regenerating the binding

`bind/bind_postgres.das` parses `pgsql/include/libpq-fe.h` via libclang and
regenerates `src/dasPOSTGRESQL.*`. Needs a daslang build with `dasClangBind`
enabled. Run from the repo root:

```
rm src/dasPOSTGRESQL.func_*.cpp
daslang bind/bind_postgres.das
```

## License

MIT — see [LICENSE](LICENSE). PostgreSQL and libpq are under the
[PostgreSQL License](https://www.postgresql.org/about/licence/).
