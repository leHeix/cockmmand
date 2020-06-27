#if defined _inc_cockmmand
	#endinput
#endif
#define _inc_cockmmand

#define COCKMMAND_VERSION	"1.0"

#if !defined COCK_CASE_SENSITIVE
	#define COCK_CASE_SENSITIVE true
#endif

#if !defined IS_SAMP_MOBILE
	#define IS_SAMP_MOBILE false
#endif

#if !IS_SAMP_MOBILE
	#define cockmmand(%0) if(!strcmp(%0, cmdtext, COCK_CASE_SENSITIVE))
	#define cockmmand_multiple(%0) else if(!strcmp(%0, cmdtext, COCK_CASE_SENSITIVE))

	stock GetCockmmandVersion()
	{
		return COCKMMAND_VERSION;
	}
#else
	#error Cockmmand no support samp mobile please pull request cockmmand to compatible
#endif
