#include <a_samp>

#define IS_SAMP_MOBILE false
#define COCK_CASE_SENSITIVE true
#include "cockmmand.inc"

public OnPlayerCommandText(playerid, cmdtext[])
{
	cockmmand("yadayada")
	{
		SendClientMessage(playerid, -1, "Cockmmand!");
		return 1;
	}
	cockmmand_multiple("lul")
	{
		SendClientMessage(playerid, -1, "Hi!");
		return 1;
	}
	
	return 0;
}