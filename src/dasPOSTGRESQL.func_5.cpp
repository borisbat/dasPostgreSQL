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
void Module_dasPOSTGRESQL::initFunctions_5() {
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:555:12
	makeExtern< int (*)(pg_conn *,const char *,int) , PQputnbytes , SimNode_ExtFuncCall >(lib,"PQputnbytes","PQputnbytes")
		->args({"conn","buffer","nbytes"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:556:12
	makeExtern< int (*)(pg_conn *) , PQendcopy , SimNode_ExtFuncCall >(lib,"PQendcopy","PQendcopy")
		->args({"conn"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:559:12
	makeExtern< int (*)(pg_conn *,int) , PQsetnonblocking , SimNode_ExtFuncCall >(lib,"PQsetnonblocking","PQsetnonblocking")
		->args({"conn","arg"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:560:12
	makeExtern< int (*)(const pg_conn *) , PQisnonblocking , SimNode_ExtFuncCall >(lib,"PQisnonblocking","PQisnonblocking")
		->args({"conn"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:561:12
	makeExtern< int (*)() , PQisthreadsafe , SimNode_ExtFuncCall >(lib,"PQisthreadsafe","PQisthreadsafe")
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:562:15
	makeExtern< PGPing (*)(const char *) , PQping , SimNode_ExtFuncCall >(lib,"PQping","PQping")
		->args({"conninfo"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:563:15
	makeExtern< PGPing (*)(const char *const *,const char *const *,int) , PQpingParams , SimNode_ExtFuncCall >(lib,"PQpingParams","PQpingParams")
		->args({"keywords","values","expand_dbname"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:567:12
	makeExtern< int (*)(pg_conn *) , PQflush , SimNode_ExtFuncCall >(lib,"PQflush","PQflush")
		->args({"conn"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:582:23
	makeExtern< ExecStatusType (*)(const pg_result *) , PQresultStatus , SimNode_ExtFuncCall >(lib,"PQresultStatus","PQresultStatus")
		->args({"res"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:583:14
	makeExtern< char * (*)(ExecStatusType) , PQresStatus , SimNode_ExtFuncCall >(lib,"PQresStatus","PQresStatus")
		->args({"status"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:584:14
	makeExtern< char * (*)(const pg_result *) , PQresultErrorMessage , SimNode_ExtFuncCall >(lib,"PQresultErrorMessage","PQresultErrorMessage")
		->args({"res"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:585:14
	makeExtern< char * (*)(const pg_result *,PGVerbosity,PGContextVisibility) , PQresultVerboseErrorMessage , SimNode_ExtFuncCall >(lib,"PQresultVerboseErrorMessage","PQresultVerboseErrorMessage")
		->args({"res","verbosity","show_context"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:588:14
	makeExtern< char * (*)(const pg_result *,int) , PQresultErrorField , SimNode_ExtFuncCall >(lib,"PQresultErrorField","PQresultErrorField")
		->args({"res","fieldcode"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:589:12
	makeExtern< int (*)(const pg_result *) , PQntuples , SimNode_ExtFuncCall >(lib,"PQntuples","PQntuples")
		->args({"res"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:590:12
	makeExtern< int (*)(const pg_result *) , PQnfields , SimNode_ExtFuncCall >(lib,"PQnfields","PQnfields")
		->args({"res"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:591:12
	makeExtern< int (*)(const pg_result *) , PQbinaryTuples , SimNode_ExtFuncCall >(lib,"PQbinaryTuples","PQbinaryTuples")
		->args({"res"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:592:14
	makeExtern< char * (*)(const pg_result *,int) , PQfname , SimNode_ExtFuncCall >(lib,"PQfname","PQfname")
		->args({"res","field_num"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:593:12
	makeExtern< int (*)(const pg_result *,const char *) , PQfnumber , SimNode_ExtFuncCall >(lib,"PQfnumber","PQfnumber")
		->args({"res","field_name"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:594:12
	makeExtern< unsigned int (*)(const pg_result *,int) , PQftable , SimNode_ExtFuncCall >(lib,"PQftable","PQftable")
		->args({"res","field_num"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:595:12
	makeExtern< int (*)(const pg_result *,int) , PQftablecol , SimNode_ExtFuncCall >(lib,"PQftablecol","PQftablecol")
		->args({"res","field_num"})
		->addToModule(*this, SideEffects::worstDefault);
}
}

