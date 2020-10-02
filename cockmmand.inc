#if defined _inc_cockmmand
	#endinput
#endif
#define _inc_cockmmand

#define COCKMMAND_VERSION	"2.0-fart"

#if !defined COCK_CASE_SENSITIVE
	#define COCK_CASE_SENSITIVE true
#endif

forward COCK_Init();

stock GetCockmmandVersion()
{
	return COCKMMAND_VERSION;
}

static COCK_PreInit()
{
	#if defined cockmmand
		print("CockMmand ran into an exception. Errors? No. Exiting...);
		SendRconCommand("exit");
	#endif

	return 1;
}

#if defined FILTERSCRIPT
	public OnFilterScriptInit()
#else
	public OnGameModeInit()
#endif
	{
		COCK_PreInit();
		
		#if defined COCK_Init
			COCK_Init();
		#endif

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

#define cockmmand(%0) if(!strcmp(%0, cmdtext, COCK_CASE_SENSITIVE))
#define cockmmand_multiple(%0) else if(!strcmp(%0, cmdtext, COCK_CASE_SENSITIVE))
#define COCKCMD:%0 cockmmand(%0)

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
