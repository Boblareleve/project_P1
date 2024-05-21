#include "print.h"



// max 5 pion + num case

// num case -> xx

// +--------+
// |xx bbjvr|
// +--------+

//♞ ■♞ ■ ♟

void print_board()
{
    //printf(B_BLUE_ANSI"■\n♞    ■■"RESET_ANSI);
    
    
    char empty[] = " ";
    char *tmp[5]; // not null terminated
    for (int i = 0; i < 5; i++)
    {
        tmp[i] = empty;
    }

#ifdef USE_ANSI
    char r[] = RED_ANSI"♞"RESET_ANSI;
    char b[] = BLUE_ANSI"♞"RESET_ANSI;
    char y[] = YELLOW_ANSI"♞"RESET_ANSI;
    char g[] = GREEN_ANSI"♞"RESET_ANSI;
#endif
#ifndef USE_ANSI
    char r[] = RED_ANSI"r"RESET_ANSI;
    char b[] = BLUE_ANSI"b"RESET_ANSI;
    char y[] = YELLOW_ANSI"j"RESET_ANSI;
    char g[] = GREEN_ANSI"v"RESET_ANSI;
#endif


            
    printf("\n");
    printf("|%02d %s%s%s%s%s|", 0, tmp[0], tmp[1], tmp[2], tmp[3], tmp[4]);





}