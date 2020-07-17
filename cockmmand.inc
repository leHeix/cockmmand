#if defined _inc_cockmmand
	#endinput
#endif
#define _inc_cockmmand

#define COCKMMAND_VERSION	"2.0"

#if !defined COCK_CASE_SENSITIVE
	#define COCK_CASE_SENSITIVE true
#endif

static cock_commands_count = 0;

forward COCK_Init(command_count);

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
			COCK_Init(cock_commands_count);
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

#define cockmmand(%0) cock_commands_count++; if(!strcmp(%0, cmdtext, COCK_CASE_SENSITIVE))
#define cockmmand_multiple(%0) else if(cock_commands_count++ != 1 && !strcmp(%0, cmdtext, COCK_CASE_SENSITIVE))
#define COCKCMD:%0 cockmmand(%0)
