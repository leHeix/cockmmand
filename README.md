# CockMmand  
**Fastest and easy-to-use command processor for SA-MP**  

## Benchmarks
By **kyro#9315**
![cockbench](https://i.imgur.com/zYPzXeQ.png)

## Support
no-reply@cockmmand.com

## Usage
Simply, use it like this:
```pawn
#include <cockmmand>
public COCK_Init(command_count)
{
    printf("We have %d commands!", command_count);
    return 1;
}

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
public COCK_Init(command_count)
{
    printf("We have %d commands!", command_count);
    return 1;
}

public OnPlayerCommandText(playerid, cmdtext[])
{
    COCKCMD:command
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
- Place in `serverroot/pawno/include`. Final path should look like this: `serverroot/pawno/include/cockmmand.inc`.
- Profit!
