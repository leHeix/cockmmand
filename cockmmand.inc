#if defined _inc_cockmmand
	#endinput
#endif
#define _inc_cockmmand

#define cockmmand(%0) if(!strcmp(%0, cmdtext, COCK_CASE_SENSITIVE))
#define cockmmand_multiple(%0) else if(!strcmp(%0, cmdtext, COCK_CASE_SENSITIVE))
