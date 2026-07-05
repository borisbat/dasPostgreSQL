// this file is generated via Daslang automatic binder
// all user modifications will be lost after this file is re-generated

// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:732:16
struct _PGpromptOAuthDevice_GeneratedAnnotation : ManagedStructureAnnotation<_PGpromptOAuthDevice> {
	_PGpromptOAuthDevice_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("_PGpromptOAuthDevice", ml, "_PGpromptOAuthDevice") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(verification_uri)>("verification_uri","verification_uri");
		addField<DAS_BIND_MANAGED_FIELD(user_code)>("user_code","user_code");
		addField<DAS_BIND_MANAGED_FIELD(verification_uri_complete)>("verification_uri_complete","verification_uri_complete");
		addField<DAS_BIND_MANAGED_FIELD(expires_in)>("expires_in","expires_in");
	}
};

// from D:/DASPKG/dasPostgreSQL/pgsql/include/libpq-fe.h:752:16
struct PGoauthBearerRequest_GeneratedAnnotation : ManagedStructureAnnotation<PGoauthBearerRequest> {
	PGoauthBearerRequest_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("PGoauthBearerRequest", ml, "PGoauthBearerRequest") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(openid_configuration)>("openid_configuration","openid_configuration");
		addField<DAS_BIND_MANAGED_FIELD(scope)>("scope","scope");
		addField<DAS_BIND_MANAGED_FIELD(token)>("token","token");
		addField<DAS_BIND_MANAGED_FIELD(user)>("user","user");
	}
};

