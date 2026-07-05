// this file is generated via Daslang automatic binder
// all user modifications will be lost after this file is re-generated

template <> struct cast_arg<_PGpromptOAuthDevice> {
	static __forceinline const _PGpromptOAuthDevice & to ( Context & ctx, SimNode * node ) {
		vec4f res = node->eval(ctx);
		return * cast<_PGpromptOAuthDevice *>::to(res);
	}
};
template <> struct cast_arg<PGoauthBearerRequest> {
	static __forceinline const PGoauthBearerRequest & to ( Context & ctx, SimNode * node ) {
		vec4f res = node->eval(ctx);
		return * cast<PGoauthBearerRequest *>::to(res);
	}
};
