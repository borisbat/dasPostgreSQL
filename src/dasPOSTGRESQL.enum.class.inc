// this file is generated via Daslang automatic binder
// all user modifications will be lost after this file is re-generated

// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:82:9
class Enumeration_ConnStatusType : public das::Enumeration {
public:
	Enumeration_ConnStatusType() : das::Enumeration("ConnStatusType") {
		external = true;
		cppName = "ConnStatusType";
		baseType = (das::Type) das::ToBasicType<int>::type;
		addIEx("CONNECTION_OK", "CONNECTION_OK", int64_t(ConnStatusType::CONNECTION_OK), das::LineInfo());
		addIEx("CONNECTION_BAD", "CONNECTION_BAD", int64_t(ConnStatusType::CONNECTION_BAD), das::LineInfo());
		addIEx("CONNECTION_STARTED", "CONNECTION_STARTED", int64_t(ConnStatusType::CONNECTION_STARTED), das::LineInfo());
		addIEx("CONNECTION_MADE", "CONNECTION_MADE", int64_t(ConnStatusType::CONNECTION_MADE), das::LineInfo());
		addIEx("CONNECTION_AWAITING_RESPONSE", "CONNECTION_AWAITING_RESPONSE", int64_t(ConnStatusType::CONNECTION_AWAITING_RESPONSE), das::LineInfo());
		addIEx("CONNECTION_AUTH_OK", "CONNECTION_AUTH_OK", int64_t(ConnStatusType::CONNECTION_AUTH_OK), das::LineInfo());
		addIEx("CONNECTION_SETENV", "CONNECTION_SETENV", int64_t(ConnStatusType::CONNECTION_SETENV), das::LineInfo());
		addIEx("CONNECTION_SSL_STARTUP", "CONNECTION_SSL_STARTUP", int64_t(ConnStatusType::CONNECTION_SSL_STARTUP), das::LineInfo());
		addIEx("CONNECTION_NEEDED", "CONNECTION_NEEDED", int64_t(ConnStatusType::CONNECTION_NEEDED), das::LineInfo());
		addIEx("CONNECTION_CHECK_WRITABLE", "CONNECTION_CHECK_WRITABLE", int64_t(ConnStatusType::CONNECTION_CHECK_WRITABLE), das::LineInfo());
		addIEx("CONNECTION_CONSUME", "CONNECTION_CONSUME", int64_t(ConnStatusType::CONNECTION_CONSUME), das::LineInfo());
		addIEx("CONNECTION_GSS_STARTUP", "CONNECTION_GSS_STARTUP", int64_t(ConnStatusType::CONNECTION_GSS_STARTUP), das::LineInfo());
		addIEx("CONNECTION_CHECK_TARGET", "CONNECTION_CHECK_TARGET", int64_t(ConnStatusType::CONNECTION_CHECK_TARGET), das::LineInfo());
		addIEx("CONNECTION_CHECK_STANDBY", "CONNECTION_CHECK_STANDBY", int64_t(ConnStatusType::CONNECTION_CHECK_STANDBY), das::LineInfo());
		addIEx("CONNECTION_ALLOCATED", "CONNECTION_ALLOCATED", int64_t(ConnStatusType::CONNECTION_ALLOCATED), das::LineInfo());
		addIEx("CONNECTION_AUTHENTICATING", "CONNECTION_AUTHENTICATING", int64_t(ConnStatusType::CONNECTION_AUTHENTICATING), das::LineInfo());
	}
};

// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:113:9
class Enumeration_PostgresPollingStatusType : public das::Enumeration {
public:
	Enumeration_PostgresPollingStatusType() : das::Enumeration("PostgresPollingStatusType") {
		external = true;
		cppName = "PostgresPollingStatusType";
		baseType = (das::Type) das::ToBasicType<int>::type;
		addIEx("PGRES_POLLING_FAILED", "PGRES_POLLING_FAILED", int64_t(PostgresPollingStatusType::PGRES_POLLING_FAILED), das::LineInfo());
		addIEx("PGRES_POLLING_READING", "PGRES_POLLING_READING", int64_t(PostgresPollingStatusType::PGRES_POLLING_READING), das::LineInfo());
		addIEx("PGRES_POLLING_WRITING", "PGRES_POLLING_WRITING", int64_t(PostgresPollingStatusType::PGRES_POLLING_WRITING), das::LineInfo());
		addIEx("PGRES_POLLING_OK", "PGRES_POLLING_OK", int64_t(PostgresPollingStatusType::PGRES_POLLING_OK), das::LineInfo());
		addIEx("PGRES_POLLING_ACTIVE", "PGRES_POLLING_ACTIVE", int64_t(PostgresPollingStatusType::PGRES_POLLING_ACTIVE), das::LineInfo());
	}
};

// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:122:9
class Enumeration_ExecStatusType : public das::Enumeration {
public:
	Enumeration_ExecStatusType() : das::Enumeration("ExecStatusType") {
		external = true;
		cppName = "ExecStatusType";
		baseType = (das::Type) das::ToBasicType<int>::type;
		addIEx("PGRES_EMPTY_QUERY", "PGRES_EMPTY_QUERY", int64_t(ExecStatusType::PGRES_EMPTY_QUERY), das::LineInfo());
		addIEx("PGRES_COMMAND_OK", "PGRES_COMMAND_OK", int64_t(ExecStatusType::PGRES_COMMAND_OK), das::LineInfo());
		addIEx("PGRES_TUPLES_OK", "PGRES_TUPLES_OK", int64_t(ExecStatusType::PGRES_TUPLES_OK), das::LineInfo());
		addIEx("PGRES_COPY_OUT", "PGRES_COPY_OUT", int64_t(ExecStatusType::PGRES_COPY_OUT), das::LineInfo());
		addIEx("PGRES_COPY_IN", "PGRES_COPY_IN", int64_t(ExecStatusType::PGRES_COPY_IN), das::LineInfo());
		addIEx("PGRES_BAD_RESPONSE", "PGRES_BAD_RESPONSE", int64_t(ExecStatusType::PGRES_BAD_RESPONSE), das::LineInfo());
		addIEx("PGRES_NONFATAL_ERROR", "PGRES_NONFATAL_ERROR", int64_t(ExecStatusType::PGRES_NONFATAL_ERROR), das::LineInfo());
		addIEx("PGRES_FATAL_ERROR", "PGRES_FATAL_ERROR", int64_t(ExecStatusType::PGRES_FATAL_ERROR), das::LineInfo());
		addIEx("PGRES_COPY_BOTH", "PGRES_COPY_BOTH", int64_t(ExecStatusType::PGRES_COPY_BOTH), das::LineInfo());
		addIEx("PGRES_SINGLE_TUPLE", "PGRES_SINGLE_TUPLE", int64_t(ExecStatusType::PGRES_SINGLE_TUPLE), das::LineInfo());
		addIEx("PGRES_PIPELINE_SYNC", "PGRES_PIPELINE_SYNC", int64_t(ExecStatusType::PGRES_PIPELINE_SYNC), das::LineInfo());
		addIEx("PGRES_PIPELINE_ABORTED", "PGRES_PIPELINE_ABORTED", int64_t(ExecStatusType::PGRES_PIPELINE_ABORTED), das::LineInfo());
		addIEx("PGRES_TUPLES_CHUNK", "PGRES_TUPLES_CHUNK", int64_t(ExecStatusType::PGRES_TUPLES_CHUNK), das::LineInfo());
	}
};

// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:145:9
class Enumeration_PGTransactionStatusType : public das::Enumeration {
public:
	Enumeration_PGTransactionStatusType() : das::Enumeration("PGTransactionStatusType") {
		external = true;
		cppName = "PGTransactionStatusType";
		baseType = (das::Type) das::ToBasicType<int>::type;
		addIEx("PQTRANS_IDLE", "PQTRANS_IDLE", int64_t(PGTransactionStatusType::PQTRANS_IDLE), das::LineInfo());
		addIEx("PQTRANS_ACTIVE", "PQTRANS_ACTIVE", int64_t(PGTransactionStatusType::PQTRANS_ACTIVE), das::LineInfo());
		addIEx("PQTRANS_INTRANS", "PQTRANS_INTRANS", int64_t(PGTransactionStatusType::PQTRANS_INTRANS), das::LineInfo());
		addIEx("PQTRANS_INERROR", "PQTRANS_INERROR", int64_t(PGTransactionStatusType::PQTRANS_INERROR), das::LineInfo());
		addIEx("PQTRANS_UNKNOWN", "PQTRANS_UNKNOWN", int64_t(PGTransactionStatusType::PQTRANS_UNKNOWN), das::LineInfo());
	}
};

// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:154:9
class Enumeration_PGVerbosity : public das::Enumeration {
public:
	Enumeration_PGVerbosity() : das::Enumeration("PGVerbosity") {
		external = true;
		cppName = "PGVerbosity";
		baseType = (das::Type) das::ToBasicType<int>::type;
		addIEx("PQERRORS_TERSE", "PQERRORS_TERSE", int64_t(PGVerbosity::PQERRORS_TERSE), das::LineInfo());
		addIEx("PQERRORS_DEFAULT", "PQERRORS_DEFAULT", int64_t(PGVerbosity::PQERRORS_DEFAULT), das::LineInfo());
		addIEx("PQERRORS_VERBOSE", "PQERRORS_VERBOSE", int64_t(PGVerbosity::PQERRORS_VERBOSE), das::LineInfo());
		addIEx("PQERRORS_SQLSTATE", "PQERRORS_SQLSTATE", int64_t(PGVerbosity::PQERRORS_SQLSTATE), das::LineInfo());
	}
};

// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:162:9
class Enumeration_PGContextVisibility : public das::Enumeration {
public:
	Enumeration_PGContextVisibility() : das::Enumeration("PGContextVisibility") {
		external = true;
		cppName = "PGContextVisibility";
		baseType = (das::Type) das::ToBasicType<int>::type;
		addIEx("PQSHOW_CONTEXT_NEVER", "PQSHOW_CONTEXT_NEVER", int64_t(PGContextVisibility::PQSHOW_CONTEXT_NEVER), das::LineInfo());
		addIEx("PQSHOW_CONTEXT_ERRORS", "PQSHOW_CONTEXT_ERRORS", int64_t(PGContextVisibility::PQSHOW_CONTEXT_ERRORS), das::LineInfo());
		addIEx("PQSHOW_CONTEXT_ALWAYS", "PQSHOW_CONTEXT_ALWAYS", int64_t(PGContextVisibility::PQSHOW_CONTEXT_ALWAYS), das::LineInfo());
	}
};

// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:174:9
class Enumeration_PGPing : public das::Enumeration {
public:
	Enumeration_PGPing() : das::Enumeration("PGPing") {
		external = true;
		cppName = "PGPing";
		baseType = (das::Type) das::ToBasicType<int>::type;
		addIEx("PQPING_OK", "PQPING_OK", int64_t(PGPing::PQPING_OK), das::LineInfo());
		addIEx("PQPING_REJECT", "PQPING_REJECT", int64_t(PGPing::PQPING_REJECT), das::LineInfo());
		addIEx("PQPING_NO_RESPONSE", "PQPING_NO_RESPONSE", int64_t(PGPing::PQPING_NO_RESPONSE), das::LineInfo());
		addIEx("PQPING_NO_ATTEMPT", "PQPING_NO_ATTEMPT", int64_t(PGPing::PQPING_NO_ATTEMPT), das::LineInfo());
	}
};

// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:185:9
class Enumeration_PGpipelineStatus : public das::Enumeration {
public:
	Enumeration_PGpipelineStatus() : das::Enumeration("PGpipelineStatus") {
		external = true;
		cppName = "PGpipelineStatus";
		baseType = (das::Type) das::ToBasicType<int>::type;
		addIEx("PQ_PIPELINE_OFF", "PQ_PIPELINE_OFF", int64_t(PGpipelineStatus::PQ_PIPELINE_OFF), das::LineInfo());
		addIEx("PQ_PIPELINE_ON", "PQ_PIPELINE_ON", int64_t(PGpipelineStatus::PQ_PIPELINE_ON), das::LineInfo());
		addIEx("PQ_PIPELINE_ABORTED", "PQ_PIPELINE_ABORTED", int64_t(PGpipelineStatus::PQ_PIPELINE_ABORTED), das::LineInfo());
	}
};

// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:192:9
class Enumeration_PGauthData : public das::Enumeration {
public:
	Enumeration_PGauthData() : das::Enumeration("PGauthData") {
		external = true;
		cppName = "PGauthData";
		baseType = (das::Type) das::ToBasicType<int>::type;
		addIEx("PQAUTHDATA_PROMPT_OAUTH_DEVICE", "PQAUTHDATA_PROMPT_OAUTH_DEVICE", int64_t(PGauthData::PQAUTHDATA_PROMPT_OAUTH_DEVICE), das::LineInfo());
		addIEx("PQAUTHDATA_OAUTH_BEARER_TOKEN", "PQAUTHDATA_OAUTH_BEARER_TOKEN", int64_t(PGauthData::PQAUTHDATA_OAUTH_BEARER_TOKEN), das::LineInfo());
	}
};

