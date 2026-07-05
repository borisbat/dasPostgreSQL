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
void Module_dasPOSTGRESQL::initFunctions_6() {
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:596:12
	makeExtern< int (*)(const pg_result *,int) , PQfformat , SimNode_ExtFuncCall >(lib,"PQfformat","PQfformat")
		->args({"res","field_num"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:597:12
	makeExtern< unsigned int (*)(const pg_result *,int) , PQftype , SimNode_ExtFuncCall >(lib,"PQftype","PQftype")
		->args({"res","field_num"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:598:12
	makeExtern< int (*)(const pg_result *,int) , PQfsize , SimNode_ExtFuncCall >(lib,"PQfsize","PQfsize")
		->args({"res","field_num"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:599:12
	makeExtern< int (*)(const pg_result *,int) , PQfmod , SimNode_ExtFuncCall >(lib,"PQfmod","PQfmod")
		->args({"res","field_num"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:600:14
	makeExtern< char * (*)(pg_result *) , PQcmdStatus , SimNode_ExtFuncCall >(lib,"PQcmdStatus","PQcmdStatus")
		->args({"res"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:601:14
	makeExtern< char * (*)(const pg_result *) , PQoidStatus , SimNode_ExtFuncCall >(lib,"PQoidStatus","PQoidStatus")
		->args({"res"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:602:12
	makeExtern< unsigned int (*)(const pg_result *) , PQoidValue , SimNode_ExtFuncCall >(lib,"PQoidValue","PQoidValue")
		->args({"res"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:603:14
	makeExtern< char * (*)(pg_result *) , PQcmdTuples , SimNode_ExtFuncCall >(lib,"PQcmdTuples","PQcmdTuples")
		->args({"res"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:604:14
	makeExtern< char * (*)(const pg_result *,int,int) , PQgetvalue , SimNode_ExtFuncCall >(lib,"PQgetvalue","PQgetvalue")
		->args({"res","tup_num","field_num"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:605:12
	makeExtern< int (*)(const pg_result *,int,int) , PQgetlength , SimNode_ExtFuncCall >(lib,"PQgetlength","PQgetlength")
		->args({"res","tup_num","field_num"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:606:12
	makeExtern< int (*)(const pg_result *,int,int) , PQgetisnull , SimNode_ExtFuncCall >(lib,"PQgetisnull","PQgetisnull")
		->args({"res","tup_num","field_num"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:607:12
	makeExtern< int (*)(const pg_result *) , PQnparams , SimNode_ExtFuncCall >(lib,"PQnparams","PQnparams")
		->args({"res"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:608:12
	makeExtern< unsigned int (*)(const pg_result *,int) , PQparamtype , SimNode_ExtFuncCall >(lib,"PQparamtype","PQparamtype")
		->args({"res","param_num"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:611:18
	makeExtern< pg_result * (*)(pg_conn *,const char *) , PQdescribePrepared , SimNode_ExtFuncCall >(lib,"PQdescribePrepared","PQdescribePrepared")
		->args({"conn","stmt"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:612:18
	makeExtern< pg_result * (*)(pg_conn *,const char *) , PQdescribePortal , SimNode_ExtFuncCall >(lib,"PQdescribePortal","PQdescribePortal")
		->args({"conn","portal"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:613:12
	makeExtern< int (*)(pg_conn *,const char *) , PQsendDescribePrepared , SimNode_ExtFuncCall >(lib,"PQsendDescribePrepared","PQsendDescribePrepared")
		->args({"conn","stmt"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:614:12
	makeExtern< int (*)(pg_conn *,const char *) , PQsendDescribePortal , SimNode_ExtFuncCall >(lib,"PQsendDescribePortal","PQsendDescribePortal")
		->args({"conn","portal"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:617:18
	makeExtern< pg_result * (*)(pg_conn *,const char *) , PQclosePrepared , SimNode_ExtFuncCall >(lib,"PQclosePrepared","PQclosePrepared")
		->args({"conn","stmt"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:618:18
	makeExtern< pg_result * (*)(pg_conn *,const char *) , PQclosePortal , SimNode_ExtFuncCall >(lib,"PQclosePortal","PQclosePortal")
		->args({"conn","portal"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:619:12
	makeExtern< int (*)(pg_conn *,const char *) , PQsendClosePrepared , SimNode_ExtFuncCall >(lib,"PQsendClosePrepared","PQsendClosePrepared")
		->args({"conn","stmt"})
		->addToModule(*this, SideEffects::worstDefault);
}
}

