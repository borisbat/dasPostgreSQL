#pragma once

#include "cb_dasPOSTGRESQL.h"
#include "need_dasPOSTGRESQL.h"

namespace das {
    PGresult * das_pq_exec_params ( PGconn * conn, const char * sql,
        const TArray<char *> & values, const TArray<uint8_t> & nulls, const TArray<uint32_t> & oids,
        Context * context, LineInfoArg * at );
}
