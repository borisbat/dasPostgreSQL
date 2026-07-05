#include "daScript/misc/platform.h"

#include "daScript/ast/ast.h"
#include "daScript/ast/ast_interop.h"
#include "daScript/ast/ast_typefactory_bind.h"
#include "daScript/ast/ast_handle.h"
#include "daScript/simulate/bind_enum.h"

#include "dasPOSTGRESQL.h"

#include "aot_postgres.h"

namespace das {

void Module_dasPOSTGRESQL::initMain() {

    addExtern<DAS_BIND_FUN(das_pq_exec_params)>(*this,lib,"pq_exec_params",
        SideEffects::worstDefault, "das_pq_exec_params")
            ->args({"conn","sql","values","nulls","oids","context","at"});

    for ( auto & pfn : this->functions.each() ) {
        // fixup module functions, so that there is a string cast
        bool anyString = false;
        for ( auto & arg : pfn->arguments ) {
            if ( arg->type->isString() && !arg->type->ref ) {
                anyString = true;
            }
        }
        if ( anyString ) {
            pfn->needStringCast = true;
        }
    }
}

ModuleAotType Module_dasPOSTGRESQL::aotRequire ( TextWriter & tw ) const {
    tw << "#include \"../modules/dasPostgreSQL/src/aot_postgres.h\"\n";
    return ModuleAotType::cpp;
}

}
