options gen2
require postgres/postgres_boost
require daslib/sql_linq
require daslib/fio

// Quick start: [sql_table] + typed CRUD + a compile-time-checked _sql chain.
// Run: daslang -load_module <path-to-dasPostgreSQL> examples/quick_start.das
// Point DAS_PG_CONNINFO at your server, e.g. "host=localhost dbname=mydb user=me".

[sql_table(name = "Users")]
struct User {
    @sql_primary_key Id : int64
    Name : string
    Age : int
}

def conninfo : string {
    if (has_env_variable("DAS_PG_CONNINFO")) return get_env_variable("DAS_PG_CONNINFO")
    return "host=localhost port=5499 user=postgres dbname=postgres"
}

[export]
def main {
    print("libpq {libpq_version()}\n")
    with_postgres(conninfo()) $(db) {
        print("server {postgres_server_version(db)}\n")
        db |> exec("DROP TABLE IF EXISTS \"Users\"")
        db |> create_table(type<User>)
        db |> insert([
            User(Id = int64(0), Name = "Ada", Age = 36),
            User(Id = int64(0), Name = "Bob", Age = 41),
            User(Id = int64(0), Name = "Cid", Age = 17)])

        let adults = _sql(db |> select_from(type<User>) |> _where(_.Age >= 18) |> _order_by(_.Name))
        for (u in adults) {
            print("#{u.Id} {u.Name} ({u.Age})\n")
        }

        let n = _sql(db |> select_from(type<User>) |> count())
        print("{n} users total; the adults query was:\n  {_sql_text(db |> select_from(type<User>) |> _where(_.Age >= 18) |> _order_by(_.Name))}\n")
        db |> exec("DROP TABLE \"Users\"")
    }
}
