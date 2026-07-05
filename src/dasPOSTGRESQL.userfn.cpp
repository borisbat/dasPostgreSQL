#include "daScript/misc/platform.h"

#include "daScript/ast/ast.h"
#include "daScript/ast/ast_interop.h"
#include "daScript/ast/ast_typefactory_bind.h"
#include "daScript/ast/ast_handle.h"
#include "daScript/simulate/bind_enum.h"
#include "daScript/simulate/aot.h"

#include "dasPOSTGRESQL.h"
#include "aot_postgres.h"

#include <vector>

namespace das {

// ============================================================================
// PQexecParams marshaling: libpq takes the whole parameter set as C arrays at
// execute time (no per-index bind API), and `const char * const *` cannot be
// produced from daslang — so postgres_boost accumulates text-format params on
// its PgStmt struct and passes three parallel das arrays here.
//
// All values travel in TEXT format (resultFormat=0 too); explicit per-param
// type OIDs (int8/float8/text/bytea, from the das bind rail) keep $n type
// inference from ever failing server-side. nulls[i] != 0 sends SQL NULL.
// ============================================================================

PGresult * das_pq_exec_params ( PGconn * conn, const char * sql,
        const TArray<char *> & values, const TArray<uint8_t> & nulls, const TArray<uint32_t> & oids,
        Context * context, LineInfoArg * at ) {
    if ( !conn ) context->throw_error_at(at, "das_pq_exec_params: connection is null");
    if ( !sql ) context->throw_error_at(at, "das_pq_exec_params: sql is null");
    uint32_t n = values.size;
    if ( nulls.size != n || oids.size != n ) {
        context->throw_error_at(at, "das_pq_exec_params: parallel param arrays disagree (%u values, %u nulls, %u oids)",
            n, nulls.size, oids.size);
    }
    std::vector<const char *> pvals(n);
    std::vector<Oid> ptypes(n);
    auto vdata = (char **) values.data;
    auto ndata = (uint8_t *) nulls.data;
    auto odata = (uint32_t *) oids.data;
    for ( uint32_t i = 0; i < n; ++i ) {
        if ( ndata[i] ) {
            pvals[i] = nullptr;
        } else {
            // das empty string is a null char* — libpq needs a real "" for non-NULL
            pvals[i] = vdata[i] ? vdata[i] : "";
        }
        ptypes[i] = (Oid) odata[i];
    }
    return PQexecParams(conn, sql, (int) n,
        n ? ptypes.data() : nullptr,
        n ? pvals.data() : nullptr,
        nullptr /*text values are NUL-terminated*/,
        nullptr /*all text format*/,
        0 /*text results*/);
}

}
