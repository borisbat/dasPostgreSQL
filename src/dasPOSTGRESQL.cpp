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
#include "dasPOSTGRESQL.struct.impl.inc"
namespace das {
#include "dasPOSTGRESQL.enum.class.inc"
#include "dasPOSTGRESQL.struct.class.inc"
#include "dasPOSTGRESQL.func.aot.inc"
Module_dasPOSTGRESQL::Module_dasPOSTGRESQL() : Module("postgres") {
}
bool Module_dasPOSTGRESQL::initDependencies() {
	if ( initialized ) return true;
	initialized = true;
	lib.addModule(this);
	lib.addBuiltInModule();
	#include "dasPOSTGRESQL.const.inc"
	#include "dasPOSTGRESQL.enum.add.inc"
	#include "dasPOSTGRESQL.dummy.add.inc"
	#include "dasPOSTGRESQL.struct.add.inc"
	#include "dasPOSTGRESQL.struct.postadd.inc"
	#include "dasPOSTGRESQL.alias.add.inc"
	#include "dasPOSTGRESQL.func.reg.inc"
	initMain();
	return true;
}
REGISTER_DYN_MODULE(Module_dasPOSTGRESQL,Module_dasPOSTGRESQL);
}
REGISTER_MODULE_IN_NAMESPACE(Module_dasPOSTGRESQL,das);

