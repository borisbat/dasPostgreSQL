// this file is generated via Daslang automatic binder
// all user modifications will be lost after this file is re-generated

// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:202:24
auto alias_PGconn = typeFactory<pg_conn>::make(lib);
alias_PGconn->alias = "PGconn";
addAlias(alias_PGconn);

// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:207:31
auto alias_PGcancelConn = typeFactory<pg_cancel_conn>::make(lib);
alias_PGcancelConn->alias = "PGcancelConn";
addAlias(alias_PGcancelConn);

// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:214:26
auto alias_PGresult = typeFactory<pg_result>::make(lib);
alias_PGresult->alias = "PGresult";
addAlias(alias_PGresult);

// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:220:26
auto alias_PGcancel = typeFactory<pg_cancel>::make(lib);
alias_PGcancel->alias = "PGcancel";
addAlias(alias_PGcancel);

// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:238:17
auto alias_pg_usec_time_t = typeFactory<long long>::make(lib);
alias_pg_usec_time_t->alias = "pg_usec_time_t";
addAlias(alias_pg_usec_time_t);

// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:241:16
auto alias_PQnoticeReceiver = typeFactory<void (*)(void *, const pg_result *)>::make(lib);
alias_PQnoticeReceiver->alias = "PQnoticeReceiver";
addAlias(alias_PQnoticeReceiver);

// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:242:16
auto alias_PQnoticeProcessor = typeFactory<void (*)(void *, const char *)>::make(lib);
alias_PQnoticeProcessor->alias = "PQnoticeProcessor";
addAlias(alias_PQnoticeProcessor);

// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:245:14
auto alias_pqbool = typeFactory<char>::make(lib);
alias_pqbool->alias = "pqbool";
addAlias(alias_pqbool);

// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:468:16
auto alias_pgthreadlock_t = typeFactory<void (*)(int)>::make(lib);
alias_pgthreadlock_t->alias = "pgthreadlock_t";
addAlias(alias_pgthreadlock_t);

// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:739:3
auto alias_PGpromptOAuthDevice = typeFactory<_PGpromptOAuthDevice>::make(lib);
alias_PGpromptOAuthDevice->alias = "PGpromptOAuthDevice";
addAlias(alias_PGpromptOAuthDevice);

// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:814:15
auto alias_PQauthDataHook_type = typeFactory<int (*)(PGauthData, pg_conn *, void *)>::make(lib);
alias_PQauthDataHook_type->alias = "PQauthDataHook_type";
addAlias(alias_PQauthDataHook_type);

// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:828:15
auto alias_PQsslKeyPassHook_OpenSSL_type = typeFactory<int (*)(char *, int, pg_conn *)>::make(lib);
alias_PQsslKeyPassHook_OpenSSL_type->alias = "PQsslKeyPassHook_OpenSSL_type";
addAlias(alias_PQsslKeyPassHook_OpenSSL_type);

