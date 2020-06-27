#if defined _inc_cockmmand
	#endinput
#endif
#define _inc_cockmmand

#define COCKMMAND_VERSION	"1.0"

#if !defined COCK_CASE_SENSITIVE
	#define COCK_CASE_SENSITIVE true
#endif

#if !defined IS_SAMP_MOBILE
	#error You must define IS_SAMP_MOBILE with true or false before including cockmmand.
#endif

#if !IS_SAMP_MOBILE
	#define cockmmand(%0) if(!strcmp(%0, cmdtext, COCK_CASE_SENSITIVE))
	#define cockmmand_multiple(%0) else if(!strcmp(%0, cmdtext, COCK_CASE_SENSITIVE))

	stock GetCockmmandVersion()
	{
		return COCKMMAND_VERSION;
	}
#else
	#if defined FILTERSCRIPT
		public OnFilterScriptInit()
	#else
		public OnGameModeInit()
		{
			print("cockmmand no compatible with samp mobile");
			SendRconCommand("exit");
			
			#if defined FILTERSCRIPT
				#if defined COCK_OnFilterScriptInit
					return COCK_OnFilterScriptInit();
				#else
					return 1;
				#endif
			#else
				#if defined COCK_OnGameModeInit
					return COCK_OnGameModeInit();
				#else
					return 1;
				#endif
			#endif
		}
	#endif
	
	#if defined FILTERSCRIPT
		#if defined _ALS_OnFilterScriptInit
			#undef OnFilterScriptInit
		#else
			#define _ALS_OnFilterScriptInit
		#endif
		#define OnFilterScriptInit COCK_OnFilterScriptInit
		#if defined COCK_OnFilterScriptInit
			forward COCK_OnFilterScriptInit();
		#endif
	#else
		#if defined _ALS_OnGameModeInit
			#undef OnGameModeInit
		#else
			#define _ALS_OnGameModeInit
		#endif
		#define OnGameModeInit COCK_OnGameModeInit
		#if defined COCK_OnGameModeInit
			forward COCK_OnGameModeInit();
		#endif
	#endif
#endif
