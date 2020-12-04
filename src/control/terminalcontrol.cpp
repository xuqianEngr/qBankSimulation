#include "terminalcontrol.h"
#include <stdlib.h>

#ifdef __OS_WINDOWS__
void clearTerminal()
{
    system("cls");
}
#else
void clearTerminal()
{
    system("clear");
}
#endif
