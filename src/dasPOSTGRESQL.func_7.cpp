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
void Module_dasPOSTGRESQL::initFunctions_7() {
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:620:12
	makeExtern< int (*)(pg_conn *,const char *) , PQsendClosePortal , SimNode_ExtFuncCall >(lib,"PQsendClosePortal","PQsendClosePortal")
		->args({"conn","portal"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:623:13
	makeExtern< void (*)(pg_result *) , PQclear , SimNode_ExtFuncCall >(lib,"PQclear","PQclear")
		->args({"res"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:626:13
	makeExtern< void (*)(void *) , PQfreemem , SimNode_ExtFuncCall >(lib,"PQfreemem","PQfreemem")
		->args({"ptr"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:636:18
	makeExtern< pg_result * (*)(pg_conn *,ExecStatusType) , PQmakeEmptyPGresult , SimNode_ExtFuncCall >(lib,"PQmakeEmptyPGresult","PQmakeEmptyPGresult")
		->args({"conn","status"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:637:18
	makeExtern< pg_result * (*)(const pg_result *,int) , PQcopyResult , SimNode_ExtFuncCall >(lib,"PQcopyResult","PQcopyResult")
		->args({"src","flags"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:639:14
	makeExtern< void * (*)(pg_result *,size_t) , PQresultAlloc , SimNode_ExtFuncCall >(lib,"PQresultAlloc","PQresultAlloc")
		->args({"res","nBytes"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:641:12
	makeExtern< int (*)(pg_result *,int,int,char *,int) , PQsetvalue , SimNode_ExtFuncCall >(lib,"PQsetvalue","PQsetvalue")
		->args({"res","tup_num","field_num","value","len"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:709:12
	makeExtern< int (*)() , PQlibVersion , SimNode_ExtFuncCall >(lib,"PQlibVersion","PQlibVersion")
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:719:12
	makeExtern< int (*)(const char *,int) , PQmblen , SimNode_ExtFuncCall >(lib,"PQmblen","PQmblen")
		->args({"s","encoding"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:722:12
	makeExtern< int (*)(const char *,int) , PQmblenBounded , SimNode_ExtFuncCall >(lib,"PQmblenBounded","PQmblenBounded")
		->args({"s","encoding"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:725:12
	makeExtern< int (*)(const char *,int) , PQdsplen , SimNode_ExtFuncCall >(lib,"PQdsplen","PQdsplen")
		->args({"s","encoding"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:728:12
	makeExtern< int (*)() , PQenv2encoding , SimNode_ExtFuncCall >(lib,"PQenv2encoding","PQenv2encoding")
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:810:14
	makeExtern< char * (*)(const char *,const char *) , PQencryptPassword , SimNode_ExtFuncCall >(lib,"PQencryptPassword","PQencryptPassword")
		->args({"passwd","user"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:811:14
	makeExtern< char * (*)(pg_conn *,const char *,const char *,const char *) , PQencryptPasswordConn , SimNode_ExtFuncCall >(lib,"PQencryptPasswordConn","PQencryptPasswordConn")
		->args({"conn","passwd","user","algorithm"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:812:18
	makeExtern< pg_result * (*)(pg_conn *,const char *,const char *) , PQchangePassword , SimNode_ExtFuncCall >(lib,"PQchangePassword","PQchangePassword")
		->args({"conn","user","passwd"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:817:12
	makeExtern< int (*)(PGauthData,pg_conn *,void *) , PQdefaultAuthDataHook , SimNode_ExtFuncCall >(lib,"PQdefaultAuthDataHook","PQdefaultAuthDataHook")
		->args({"type","conn","data"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:821:12
	makeExtern< int (*)(const char *) , pg_char_to_encoding , SimNode_ExtFuncCall >(lib,"pg_char_to_encoding","pg_char_to_encoding")
		->args({"name"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:822:20
	makeExtern< const char * (*)(int) , pg_encoding_to_char , SimNode_ExtFuncCall >(lib,"pg_encoding_to_char","pg_encoding_to_char")
		->args({"encoding"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:823:12
	makeExtern< int (*)(int) , pg_valid_server_encoding_id , SimNode_ExtFuncCall >(lib,"pg_valid_server_encoding_id","pg_valid_server_encoding_id")
		->args({"encoding"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:831:12
	makeExtern< int (*)(char *,int,pg_conn *) , PQdefaultSSLKeyPassHook_OpenSSL , SimNode_ExtFuncCall >(lib,"PQdefaultSSLKeyPassHook_OpenSSL","PQdefaultSSLKeyPassHook_OpenSSL")
		->args({"buf","size","conn"})
		->addToModule(*this, SideEffects::worstDefault);
}
}

