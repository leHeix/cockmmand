native cockmmand_process(string1[], string2[], ignorecase, length = cellmax) = strcmp;
#define cockmmand(%0) if(!cockmmand_process(%0, cmdtext, true))
#define cockmmand_multiple(%0) else if(!cockmmand_process(%0, cmdtext, true))
