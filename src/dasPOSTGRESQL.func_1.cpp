// this file is generated via Daslang automatic binder
// all user modifications will be lost after this file is re-generated

#include "daScript/misc/platform.h"
#include "daScript/ast/ast.h"
#include "daScript/ast/ast_interop.h"
#include "daScript/ast/ast_handle.h"
#include "daScript/ast/ast_typefactory_bind.h"
#include "daScript/simulate/bind_enum.h"
#include "dasPOSTGRESQL.h"
#include "need_dasPOSTGRESQL.h"
namespace das {
#include "dasPOSTGRESQL.func.aot.decl.inc"
void Module_dasPOSTGRESQL::initFunctions_1() {
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:325:16
	makeExtern< pg_conn * (*)(const char *) , PQconnectStart , SimNode_ExtFuncCall >(lib,"PQconnectStart","PQconnectStart")
		->args({"conninfo"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:326:16
	makeExtern< pg_conn * (*)(const char *const *,const char *const *,int) , PQconnectStartParams , SimNode_ExtFuncCall >(lib,"PQconnectStartParams","PQconnectStartParams")
		->args({"keywords","values","expand_dbname"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:328:34
	makeExtern< PostgresPollingStatusType (*)(pg_conn *) , PQconnectPoll , SimNode_ExtFuncCall >(lib,"PQconnectPoll","PQconnectPoll")
		->args({"conn"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:331:16
	makeExtern< pg_conn * (*)(const char *) , PQconnectdb , SimNode_ExtFuncCall >(lib,"PQconnectdb","PQconnectdb")
		->args({"conninfo"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:332:16
	makeExtern< pg_conn * (*)(const char *const *,const char *const *,int) , PQconnectdbParams , SimNode_ExtFuncCall >(lib,"PQconnectdbParams","PQconnectdbParams")
		->args({"keywords","values","expand_dbname"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:334:16
	makeExtern< pg_conn * (*)(const char *,const char *,const char *,const char *,const char *,const char *,const char *) , PQsetdbLogin , SimNode_ExtFuncCall >(lib,"PQsetdbLogin","PQsetdbLogin")
		->args({"pghost","pgport","pgoptions","pgtty","dbName","login","pwd"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:343:13
	makeExtern< void (*)(pg_conn *) , PQfinish , SimNode_ExtFuncCall >(lib,"PQfinish","PQfinish")
		->args({"conn"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:362:12
	makeExtern< int (*)(pg_conn *) , PQresetStart , SimNode_ExtFuncCall >(lib,"PQresetStart","PQresetStart")
		->args({"conn"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:363:34
	makeExtern< PostgresPollingStatusType (*)(pg_conn *) , PQresetPoll , SimNode_ExtFuncCall >(lib,"PQresetPoll","PQresetPoll")
		->args({"conn"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:366:13
	makeExtern< void (*)(pg_conn *) , PQreset , SimNode_ExtFuncCall >(lib,"PQreset","PQreset")
		->args({"conn"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:369:22
	makeExtern< pg_cancel_conn * (*)(pg_conn *) , PQcancelCreate , SimNode_ExtFuncCall >(lib,"PQcancelCreate","PQcancelCreate")
		->args({"conn"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:372:12
	makeExtern< int (*)(pg_cancel_conn *) , PQcancelStart , SimNode_ExtFuncCall >(lib,"PQcancelStart","PQcancelStart")
		->args({"cancelConn"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:375:12
	makeExtern< int (*)(pg_cancel_conn *) , PQcancelBlocking , SimNode_ExtFuncCall >(lib,"PQcancelBlocking","PQcancelBlocking")
		->args({"cancelConn"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:378:34
	makeExtern< PostgresPollingStatusType (*)(pg_cancel_conn *) , PQcancelPoll , SimNode_ExtFuncCall >(lib,"PQcancelPoll","PQcancelPoll")
		->args({"cancelConn"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:379:23
	makeExtern< ConnStatusType (*)(const pg_cancel_conn *) , PQcancelStatus , SimNode_ExtFuncCall >(lib,"PQcancelStatus","PQcancelStatus")
		->args({"cancelConn"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:380:12
	makeExtern< int (*)(const pg_cancel_conn *) , PQcancelSocket , SimNode_ExtFuncCall >(lib,"PQcancelSocket","PQcancelSocket")
		->args({"cancelConn"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:381:14
	makeExtern< char * (*)(const pg_cancel_conn *) , PQcancelErrorMessage , SimNode_ExtFuncCall >(lib,"PQcancelErrorMessage","PQcancelErrorMessage")
		->args({"cancelConn"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:382:13
	makeExtern< void (*)(pg_cancel_conn *) , PQcancelReset , SimNode_ExtFuncCall >(lib,"PQcancelReset","PQcancelReset")
		->args({"cancelConn"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:383:13
	makeExtern< void (*)(pg_cancel_conn *) , PQcancelFinish , SimNode_ExtFuncCall >(lib,"PQcancelFinish","PQcancelFinish")
		->args({"cancelConn"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:387:18
	makeExtern< pg_cancel * (*)(pg_conn *) , PQgetCancel , SimNode_ExtFuncCall >(lib,"PQgetCancel","PQgetCancel")
		->args({"conn"})
		->addToModule(*this, SideEffects::worstDefault);
}
}

