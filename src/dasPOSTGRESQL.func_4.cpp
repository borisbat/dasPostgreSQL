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
void Module_dasPOSTGRESQL::initFunctions_4() {
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:509:12
	makeExtern< int (*)(pg_conn *,const char *) , PQsendQuery , SimNode_ExtFuncCall >(lib,"PQsendQuery","PQsendQuery")
		->args({"conn","query"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:510:12
	makeExtern< int (*)(pg_conn *,const char *,int,const unsigned int *,const char *const *,const int *,const int *,int) , PQsendQueryParams , SimNode_ExtFuncCall >(lib,"PQsendQueryParams","PQsendQueryParams")
		->args({"conn","command","nParams","paramTypes","paramValues","paramLengths","paramFormats","resultFormat"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:518:12
	makeExtern< int (*)(pg_conn *,const char *,const char *,int,const unsigned int *) , PQsendPrepare , SimNode_ExtFuncCall >(lib,"PQsendPrepare","PQsendPrepare")
		->args({"conn","stmtName","query","nParams","paramTypes"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:521:12
	makeExtern< int (*)(pg_conn *,const char *,int,const char *const *,const int *,const int *,int) , PQsendQueryPrepared , SimNode_ExtFuncCall >(lib,"PQsendQueryPrepared","PQsendQueryPrepared")
		->args({"conn","stmtName","nParams","paramValues","paramLengths","paramFormats","resultFormat"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:528:12
	makeExtern< int (*)(pg_conn *) , PQsetSingleRowMode , SimNode_ExtFuncCall >(lib,"PQsetSingleRowMode","PQsetSingleRowMode")
		->args({"conn"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:529:12
	makeExtern< int (*)(pg_conn *,int) , PQsetChunkedRowsMode , SimNode_ExtFuncCall >(lib,"PQsetChunkedRowsMode","PQsetChunkedRowsMode")
		->args({"conn","chunkSize"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:530:18
	makeExtern< pg_result * (*)(pg_conn *) , PQgetResult , SimNode_ExtFuncCall >(lib,"PQgetResult","PQgetResult")
		->args({"conn"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:533:12
	makeExtern< int (*)(pg_conn *) , PQisBusy , SimNode_ExtFuncCall >(lib,"PQisBusy","PQisBusy")
		->args({"conn"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:534:12
	makeExtern< int (*)(pg_conn *) , PQconsumeInput , SimNode_ExtFuncCall >(lib,"PQconsumeInput","PQconsumeInput")
		->args({"conn"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:537:12
	makeExtern< int (*)(pg_conn *) , PQenterPipelineMode , SimNode_ExtFuncCall >(lib,"PQenterPipelineMode","PQenterPipelineMode")
		->args({"conn"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:538:12
	makeExtern< int (*)(pg_conn *) , PQexitPipelineMode , SimNode_ExtFuncCall >(lib,"PQexitPipelineMode","PQexitPipelineMode")
		->args({"conn"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:539:12
	makeExtern< int (*)(pg_conn *) , PQpipelineSync , SimNode_ExtFuncCall >(lib,"PQpipelineSync","PQpipelineSync")
		->args({"conn"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:540:12
	makeExtern< int (*)(pg_conn *) , PQsendFlushRequest , SimNode_ExtFuncCall >(lib,"PQsendFlushRequest","PQsendFlushRequest")
		->args({"conn"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:541:12
	makeExtern< int (*)(pg_conn *) , PQsendPipelineSync , SimNode_ExtFuncCall >(lib,"PQsendPipelineSync","PQsendPipelineSync")
		->args({"conn"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:547:12
	makeExtern< int (*)(pg_conn *,const char *,int) , PQputCopyData , SimNode_ExtFuncCall >(lib,"PQputCopyData","PQputCopyData")
		->args({"conn","buffer","nbytes"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:548:12
	makeExtern< int (*)(pg_conn *,const char *) , PQputCopyEnd , SimNode_ExtFuncCall >(lib,"PQputCopyEnd","PQputCopyEnd")
		->args({"conn","errormsg"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:549:12
	makeExtern< int (*)(pg_conn *,char **,int) , PQgetCopyData , SimNode_ExtFuncCall >(lib,"PQgetCopyData","PQgetCopyData")
		->args({"conn","buffer","async"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:552:12
	makeExtern< int (*)(pg_conn *,char *,int) , PQgetline , SimNode_ExtFuncCall >(lib,"PQgetline","PQgetline")
		->args({"conn","buffer","length"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:553:12
	makeExtern< int (*)(pg_conn *,const char *) , PQputline , SimNode_ExtFuncCall >(lib,"PQputline","PQputline")
		->args({"conn","string"})
		->addToModule(*this, SideEffects::worstDefault);
// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:554:12
	makeExtern< int (*)(pg_conn *,char *,int) , PQgetlineAsync , SimNode_ExtFuncCall >(lib,"PQgetlineAsync","PQgetlineAsync")
		->args({"conn","buffer","bufsize"})
		->addToModule(*this, SideEffects::worstDefault);
}
}

