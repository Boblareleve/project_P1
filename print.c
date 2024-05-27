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

static void interTile()
{
    printf("+");
    for (int i = 0; i < SIZE_TILE; i++)
        printf("-");
}


void colorHouse(color_t house)
{
    printf(B_YELLOW_ANSI"  "RESET_ANSI);
    switch (house)
    {
    case red:
        for (int i = 1; i < 4*SIZE_TILE; i++)
            printf(B_RED_ANSI"  "RESET_ANSI);
        break;
    case yellow:
        for (int i = 1; i < 4*SIZE_TILE; i++)
            printf(B_YELLOW_ANSI"  "RESET_ANSI);
        break;
    case green:
        for (int i = 1; i < 4*SIZE_TILE; i++)
            printf(B_GREEN_ANSI"  "RESET_ANSI);
        break;
    case blue:
        for (int i = 1; i < 4*SIZE_TILE; i++)
            printf(B_BLUE_ANSI"  "RESET_ANSI);
        break;
    default:
        printf("err print_line_houses");
        break;
    }
}



void printLineHouses(color_t house1, color_t house2, gameState *game, int lineNum)
{
    //printf(RESET_ANSI"+----+----+----+");
    //int table[16][3] = {
    //    {0, 67, 66}, {}
    //}
    
    colorHouse(house1);

    //for (int i = 0; i < 3; i++)
    // totalHorseCount(game, case) == 5 ? 
    printf(RESET_ANSI"|%-2d  ", lineNum+1);

    if (lineNum == 0) // première ligne
    {
        pritnf(RESET_ANSI"|%-2d  |", 68);
    }
    else if (lineNum == 32) // dernière ligne
    {
        pritnf(RESET_ANSI"|%-2d  |", 34);
    }
    else if (lineNum < 25)
        printf(B_YELLOW_ANSI"| %s  |");
    else printf(  B_RED_ANSI"| %s  |");
    

    printf(RESET_ANSI"%-2d  ", 67 - lineNum);
    printf(RESET_ANSI"|");
    

    colorHouse(house2);

    printf("\n");

    colorHouse(house1);

    //for (int i = 0; i < 8*SIZE_TILE; i++)
    //{
    //    printf(B_YELLOW_ANSI" "RESET_ANSI);
    //}

    printf(RESET_ANSI"| %s %s ", r,r);
    printf(RESET_ANSI"| %s %s ", r,r);
    printf(RESET_ANSI"| %s %s ", r,r);
    printf(RESET_ANSI"|");

    colorHouse(house2);

    printf("\n"); //21+1

}




void printBoard(gameState *game)
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



    tmp[3] = r;
            
    //printf("\n");
    //printf("|%02d %s%s%s%s%s", 0, tmp[0], tmp[1], tmp[2], tmp[3], tmp[4]); // 9 char


    game->b.yellowHouse = 4;
    game->b.greenHouse = 4;

    char tab[19][8*9];

    for (int i = 0; i < 8*SIZE_TILE; i++)
    {
        printf(B_YELLOW_ANSI" "RESET_ANSI);
    }

    //for (int i = 0; i < 5*3+1; i++)
    //    printf(RESET_ANSI" ");
    printf(RESET_ANSI"+----+----+----+");

    for (int i = 0; i < 8*SIZE_TILE; i++)
    {
        printf(B_GREEN_ANSI" "RESET_ANSI);
    }
    printf("\n"); //21+1


    printf(B_YELLOW_ANSI"  "RESET_ANSI);
    for (int i = 1; i < 4*SIZE_TILE; i++)
    {
        if (i-1 < game->b.yellowHouse)
        {
            printf("%s ", y);
        }
        else printf(B_YELLOW_ANSI"  "RESET_ANSI);
    }


    //for (int i = 0; i < 3; i++)
    printf(RESET_ANSI"|%-2d %s", 0, r);
    printf(RESET_ANSI"|%-2d %s", 0, r);
    printf(RESET_ANSI"|%-2d %s", 0, r);
    printf(RESET_ANSI"|");
    

    
    printf(B_GREEN_ANSI"  "RESET_ANSI);
    for (int i = 1; i < 4*SIZE_TILE; i++)
    {
        if (i-1 < game->b.greenHouse)
        {
            printf("%s ", g);
        }
        else printf(B_GREEN_ANSI"  "RESET_ANSI);
    }

    printf("\n");

    for (int i = 0; i < 8*SIZE_TILE; i++)
    {
        printf(B_YELLOW_ANSI" "RESET_ANSI);
    }

    printf(RESET_ANSI"|%s%s%s%s", r,r,r,r);
    printf(RESET_ANSI"|%s%s%s%s", r,r,r,r);
    printf(RESET_ANSI"|%s%s%s%s", r,r,r,r);
    printf(RESET_ANSI"|");


    for (int i = 0; i < 8*SIZE_TILE; i++)
    {
        printf(B_GREEN_ANSI" "RESET_ANSI);
    }
    printf("\n"); //21+1
    

    
    print_line_houses(yellow, green, game);
    

    

    printf("\n"); //21+1



}