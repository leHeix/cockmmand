#if defined cockmd_INCLUDED
  #endinput
#endif
#define cockmd_INCLUDED

#include <a_samp>
#if !defined _inc_y_hooks
  #tryinclude <YSI_Coding\y_hooks>
#endif

#if !defined _INC_y_inline
  #tryinclude <YSI_Coding\y_inline>
#endif

#if !defined _INC_indirection
  #tryinclude <indirection>
#endif

#if !defined _INC_y_inline
  #error y_inline couldn't be included.
#elseif !defined _INC_indirection
  #error Indirections couldn't be included.
#endif

#define cockmmand(%0) if(!strcmp(%0, cmdtext))
#define cockmmand_multiple(%0) else if(!strcmp(%0, cmdtext))
new bool:cock_DISABLED[MAX_PLAYERS];

static HTTP_Inline(index, type, const url[], Func:cb<>)
{
  new ret = HTTP(index, type, url, "Indirect_FromCallback", "ii", _:cb, true);
  if(ret)
  {
    Indirect_Claim(cb);
  }
  return ret;
}

hook OnPlayerCommandText(playerid, cmdtext[])
{
  if(cock_DISABLED[playerid]) return SendClientMessage(playerid, -1, "Venezuelans are not allowed to use Cockmmand.");
  new url[60];
  format(url, sizeof(url), "http://ip-api.com/line/%s?fields=country", GetPlayerIp(playerid));
  inline OnVenezuelaCheckFinished(index, response_code, data[])
  {
    if(!strcmp(data, "Venezuela", true))
    {
      cock_DISABLED[playerid] = true;
    }
    return 1;
  }
	HTTP_Inline(playerid, HTTP_GET, url, using inline OnVenezuelaCheckFinished);
	return 1;
}
