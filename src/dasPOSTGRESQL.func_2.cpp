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
void Module_dasPOSTGRESQL::initFunctions_2() {
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:390:13
	makeExtern< void (*)(pg_cancel *) , PQfreeCancel , SimNode_ExtFuncCall >(lib,"PQfreeCancel","PQfreeCancel")
		->args({"cancel"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:393:12
	makeExtern< int (*)(pg_cancel *,char *,int) , PQcancel , SimNode_ExtFuncCall >(lib,"PQcancel","PQcancel")
		->args({"cancel","errbuf","errbufsize"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:396:12
	makeExtern< int (*)(pg_conn *) , PQrequestCancel , SimNode_ExtFuncCall >(lib,"PQrequestCancel","PQrequestCancel")
		->args({"conn"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:399:14
	makeExtern< char * (*)(const pg_conn *) , PQdb , SimNode_ExtFuncCall >(lib,"PQdb","PQdb")
		->args({"conn"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:400:14
	makeExtern< char * (*)(const pg_conn *) , PQuser , SimNode_ExtFuncCall >(lib,"PQuser","PQuser")
		->args({"conn"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:401:14
	makeExtern< char * (*)(const pg_conn *) , PQpass , SimNode_ExtFuncCall >(lib,"PQpass","PQpass")
		->args({"conn"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:402:14
	makeExtern< char * (*)(const pg_conn *) , PQhost , SimNode_ExtFuncCall >(lib,"PQhost","PQhost")
		->args({"conn"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:403:14
	makeExtern< char * (*)(const pg_conn *) , PQhostaddr , SimNode_ExtFuncCall >(lib,"PQhostaddr","PQhostaddr")
		->args({"conn"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:404:14
	makeExtern< char * (*)(const pg_conn *) , PQport , SimNode_ExtFuncCall >(lib,"PQport","PQport")
		->args({"conn"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:405:14
	makeExtern< char * (*)(const pg_conn *) , PQtty , SimNode_ExtFuncCall >(lib,"PQtty","PQtty")
		->args({"conn"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:406:14
	makeExtern< char * (*)(const pg_conn *) , PQoptions , SimNode_ExtFuncCall >(lib,"PQoptions","PQoptions")
		->args({"conn"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:407:23
	makeExtern< ConnStatusType (*)(const pg_conn *) , PQstatus , SimNode_ExtFuncCall >(lib,"PQstatus","PQstatus")
		->args({"conn"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:408:32
	makeExtern< PGTransactionStatusType (*)(const pg_conn *) , PQtransactionStatus , SimNode_ExtFuncCall >(lib,"PQtransactionStatus","PQtransactionStatus")
		->args({"conn"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:409:20
	makeExtern< const char * (*)(const pg_conn *,const char *) , PQparameterStatus , SimNode_ExtFuncCall >(lib,"PQparameterStatus","PQparameterStatus")
		->args({"conn","paramName"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:411:12
	makeExtern< int (*)(const pg_conn *) , PQprotocolVersion , SimNode_ExtFuncCall >(lib,"PQprotocolVersion","PQprotocolVersion")
		->args({"conn"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:412:12
	makeExtern< int (*)(const pg_conn *) , PQfullProtocolVersion , SimNode_ExtFuncCall >(lib,"PQfullProtocolVersion","PQfullProtocolVersion")
		->args({"conn"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:413:12
	makeExtern< int (*)(const pg_conn *) , PQserverVersion , SimNode_ExtFuncCall >(lib,"PQserverVersion","PQserverVersion")
		->args({"conn"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:414:14
	makeExtern< char * (*)(const pg_conn *) , PQerrorMessage , SimNode_ExtFuncCall >(lib,"PQerrorMessage","PQerrorMessage")
		->args({"conn"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:415:12
	makeExtern< int (*)(const pg_conn *) , PQsocket , SimNode_ExtFuncCall >(lib,"PQsocket","PQsocket")
		->args({"conn"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:416:12
	makeExtern< int (*)(const pg_conn *) , PQbackendPID , SimNode_ExtFuncCall >(lib,"PQbackendPID","PQbackendPID")
		->args({"conn"})
		->addToModule(*this, SideEffects::worstDefault);
}
}

