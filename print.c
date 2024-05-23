#include "print.h"
#include "logic.h"
#include "board.h"



// max 5 pion + num case

// num case -> xx

//       |
// xx p|
// pppp|
//       |

//♞ ■♞ ■ ♟

static void interTile()
{
    printf("+");
    for (int i = 0; i < SIZE_TILE; i++)
        printf("-");
}


void print_board(gameState *game)
{
    //printf(B_BLUE_ANSI"■♞    ■■\n"B_RESET_ANSI);
    //printf(B_YELLOW_ANSI"■♞    ■■\n");
    //printf(B_RED_ANSI"■♞    ■■\n"B_RESET_ANSI);
    //printf(B_GREEN_ANSI"■♞    ■■\n"B_RESET_ANSI);
    //printf(RESET_ANSI"\n");
    


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
            
    //printf("\n");
    //printf("|%02d %s%s%s%s%s", 0, tmp[0], tmp[1], tmp[2], tmp[3], tmp[4]); // 9 char


    game->b.yellowHouse = 4;
    game->b.greenHouse = 4;

    char tab[][8*9];

    for (int i = 0; i < 8*SIZE_TILE; i++)
    {
        printf(B_YELLOW_ANSI" "RESET_ANSI);
    }

    for (int i = 0; i < 22; i++)
        printf(RESET_ANSI" ");

    for (int i = 0; i < 8*SIZE_TILE; i++)
    {
        printf(B_GREEN_ANSI" "RESET_ANSI);
    }
    printf("\n"); //21+1


    printf(B_YELLOW_ANSI" "RESET_ANSI);
    for (int i = 1; i < 8*SIZE_TILE; i++)
    {
        if (i-1 < game->b.yellowHouse)
        {
            printf("%s", y);
        }
        else printf(B_YELLOW_ANSI" "RESET_ANSI);
    }


    //for (int i = 0; i < 3; i++)
    printf(RESET_ANSI" %-2d ", 0);

    
    printf(B_GREEN_ANSI" "RESET_ANSI);
    for (int i = 1; i < 8*SIZE_TILE; i++)
    {
        if (i-1 < game->b.greenHouse)
        {
            printf("%s", g);
        }
        else printf(B_GREEN_ANSI" "RESET_ANSI);
    }
    

    



    for (int i = 0; i < 8*SIZE_TILE; i++)
        printf(" ");

    

    

    printf("\n"); //21+1



}