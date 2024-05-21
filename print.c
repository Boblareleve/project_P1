#include "print.h"
#include "logic.h"
#include "board.h"



// max 5 pion + num case

// num case -> xx

// +--------|
// | xx bb  |
// |    jvr |
//          |

//♞ ■♞ ■ ♟

static void interTile()
{
    printf("+");
    for (int i = 0; i < SIZE_TILE; i++)
        printf("-");
}


void print_board(gameState *game)
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

    tmp[3] = r;
            
    printf("\n");
    printf("|%02d %s%s%s%s%s", 0, tmp[0], tmp[1], tmp[2], tmp[3], tmp[4]); // 9 char


    game->b.yellowHouse = 4;
    for (int i = 0; i < 8*SIZE_TILE; i++)
    {
        if (i < game->b.yellowHouse)
        {
            printf("%s", y);
        }
        else printf(" ");
    }

    for (int i = 0; i < 8*SIZE_TILE; i++)
        printf(" ");

    



}