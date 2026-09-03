#include "daScript/misc/platform.h"

#include "daScript/ast/ast.h"
#include "daScript/ast/ast_interop.h"
#include "daScript/ast/ast_handle.h"
#include "daScript/simulate/bind_enum.h"

#include "dasPOSTGRESQL.h"

#include "aot_postgres.h"

namespace das {

void Module_dasPOSTGRESQL::initMain() {

    addExtern<DAS_BIND_FUN(das_pq_exec_params)>(*this,lib,"pq_exec_params",
        SideEffects::worstDefault, "das_pq_exec_params")
            ->args({"conn","sql","values","nulls","oids","context","at"});
}

ModuleAotType Module_dasPOSTGRESQL::aotRequire ( TextWriter & tw ) const {
    tw << "#include \"../modules/dasPostgreSQL/src/aot_postgres.h\"\n";
    return ModuleAotType::cpp;
}

}
