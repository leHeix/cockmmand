#if defined cockmd_INCLUDED
  #endinput
#endif
#define cockmd_INCLUDED

#include <a_samp>
#if !defined STRLIB_INC
  #tryinclude <strlib>
#endif

#if !defined STRLIB_INC
  #error Cockmmand depends on https://github.com/oscar-broman/strlib
#endif

#define COCKMD:%0(%1) forward cockmd_%0(%1); \
                      public cockmd_%0(%1)
#define COCKMMAND:%0(%1) COCKMD:%0(%1)
#define cockmmand(%0, %1) COCKMD:%0(%1) // old syntax
#define CMD:%0(%1) COCKMD:%0(%1) // syntax for normies

public OnPlayerCommandText(playerid, cmdtext[])
{
  strtrim(cmdtext, "/");

  new function[48];
  format(function, sizeof(function), "cockmd_%s", cmdtext);

  CallLocalFunction(function, "d", playerid);
  #if defined COCK_OnPlayerCommandText
    return COCK_OnPlayerCommandText(playerid, cmdtext[]);
  #else
    return 1;
  #endif
}

#if defined _ALS_OnPlayerCommandText
  #undef OnPlayerCommandText
#else
  #define _ALS_OnPlayerCommandText
#endif

#define OnPlayerCommandText COCK_OnPlayerCommandText
#if defined COCK_OnPlayerCommandText
  forward COCK_OnPlayerCommandText(playerid, cmdtext[]);
#endif


