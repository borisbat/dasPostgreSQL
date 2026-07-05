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
void Module_dasPOSTGRESQL::initFunctions_3() {
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:417:25
	makeExtern< PGpipelineStatus (*)(const pg_conn *) , PQpipelineStatus , SimNode_ExtFuncCall >(lib,"PQpipelineStatus","PQpipelineStatus")
		->args({"conn"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:418:12
	makeExtern< int (*)(const pg_conn *) , PQconnectionNeedsPassword , SimNode_ExtFuncCall >(lib,"PQconnectionNeedsPassword","PQconnectionNeedsPassword")
		->args({"conn"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:419:12
	makeExtern< int (*)(const pg_conn *) , PQconnectionUsedPassword , SimNode_ExtFuncCall >(lib,"PQconnectionUsedPassword","PQconnectionUsedPassword")
		->args({"conn"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:420:12
	makeExtern< int (*)(const pg_conn *) , PQconnectionUsedGSSAPI , SimNode_ExtFuncCall >(lib,"PQconnectionUsedGSSAPI","PQconnectionUsedGSSAPI")
		->args({"conn"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:421:12
	makeExtern< int (*)(const pg_conn *) , PQclientEncoding , SimNode_ExtFuncCall >(lib,"PQclientEncoding","PQclientEncoding")
		->args({"conn"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:422:12
	makeExtern< int (*)(pg_conn *,const char *) , PQsetClientEncoding , SimNode_ExtFuncCall >(lib,"PQsetClientEncoding","PQsetClientEncoding")
		->args({"conn","encoding"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:425:12
	makeExtern< int (*)(pg_conn *) , PQsslInUse , SimNode_ExtFuncCall >(lib,"PQsslInUse","PQsslInUse")
		->args({"conn"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:427:20
	makeExtern< const char * (*)(pg_conn *,const char *) , PQsslAttribute , SimNode_ExtFuncCall >(lib,"PQsslAttribute","PQsslAttribute")
		->args({"conn","attribute_name"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:428:27
	makeExtern< const char *const * (*)(pg_conn *) , PQsslAttributeNames , SimNode_ExtFuncCall >(lib,"PQsslAttributeNames","PQsslAttributeNames")
		->args({"conn"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:435:13
	makeExtern< void (*)(int) , PQinitSSL , SimNode_ExtFuncCall >(lib,"PQinitSSL","PQinitSSL")
		->args({"do_init"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:438:13
	makeExtern< void (*)(int,int) , PQinitOpenSSL , SimNode_ExtFuncCall >(lib,"PQinitOpenSSL","PQinitOpenSSL")
		->args({"do_ssl","do_crypto"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:441:12
	makeExtern< int (*)(pg_conn *) , PQgssEncInUse , SimNode_ExtFuncCall >(lib,"PQgssEncInUse","PQgssEncInUse")
		->args({"conn"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:444:14
	makeExtern< void * (*)(pg_conn *) , PQgetgssctx , SimNode_ExtFuncCall >(lib,"PQgetgssctx","PQgetgssctx")
		->args({"conn"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:447:20
	makeExtern< PGVerbosity (*)(pg_conn *,PGVerbosity) , PQsetErrorVerbosity , SimNode_ExtFuncCall >(lib,"PQsetErrorVerbosity","PQsetErrorVerbosity")
		->args({"conn","verbosity"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:450:28
	makeExtern< PGContextVisibility (*)(pg_conn *,PGContextVisibility) , PQsetErrorContextVisibility , SimNode_ExtFuncCall >(lib,"PQsetErrorContextVisibility","PQsetErrorContextVisibility")
		->args({"conn","show_context"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:481:13
	makeExtern< void (*)(pg_conn *,int) , PQsetTraceFlags , SimNode_ExtFuncCall >(lib,"PQsetTraceFlags","PQsetTraceFlags")
		->args({"conn","flags"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:486:18
	makeExtern< pg_result * (*)(pg_conn *,const char *) , PQexec , SimNode_ExtFuncCall >(lib,"PQexec","PQexec")
		->args({"conn","query"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:487:18
	makeExtern< pg_result * (*)(pg_conn *,const char *,int,const unsigned int *,const char *const *,const int *,const int *,int) , PQexecParams , SimNode_ExtFuncCall >(lib,"PQexecParams","PQexecParams")
		->args({"conn","command","nParams","paramTypes","paramValues","paramLengths","paramFormats","resultFormat"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:495:18
	makeExtern< pg_result * (*)(pg_conn *,const char *,const char *,int,const unsigned int *) , PQprepare , SimNode_ExtFuncCall >(lib,"PQprepare","PQprepare")
		->args({"conn","stmtName","query","nParams","paramTypes"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:498:18
	makeExtern< pg_result * (*)(pg_conn *,const char *,int,const char *const *,const int *,const int *,int) , PQexecPrepared , SimNode_ExtFuncCall >(lib,"PQexecPrepared","PQexecPrepared")
		->args({"conn","stmtName","nParams","paramValues","paramLengths","paramFormats","resultFormat"})
		->addToModule(*this, SideEffects::worstDefault);
}
}

