# CockMmand  
Unleash the full potential of the cock, **NOW**!  
Cockmmand offers the super cock-shenanigans (shenanicocks, yeah!) to trick the SA-MP server to use SUPER-DOOPER-FAST COMMANDS!! And not only that, it also uses all of the COCK POWER!

## Benchmarks
By **kyro#9315**
![cockbench](https://i.imgur.com/zYPzXeQ.png)

## Support
no-reply@cockmmand.com

## Usage
Simply, use it like this:
```pawn
#include <cockmmand>

public OnPlayerCommandText(playerid, cmdtext[])
{
    cockmmand("command_name")
    {
         // command code
    }
    return 1;
}
```
To add more than one command, we made simple optimization, use:
```pawn
#include <cockmmand>

public OnPlayerCommandText(playerid, cmdtext[])
{
    cockmmand("command")
    {
        // command code
    }
    cockmmand_multiple("command_2")
    {
        // code
    }
    cockmmand_multiple("command_3")
    {
        // code
    }
    return 1;
}
```
**WARNING! USAGE OUTSIDE OnPlayerCommandText WILL NOT WORK!**

## Installation  
- Download **cockmmand.inc** from branch `master`
- Place in `<path_to_include_folder>/include`. Final path should look like this: `<path_to_include_folder>/cockmmand.inc`.
- Profit!
