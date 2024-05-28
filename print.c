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
    switch (house)
    {
    case red:
        for (int i = 1; i < 4*SIZE_TILE+1; i++)
            printf(B_RED_ANSI"  "RESET_ANSI);
        break;
    case yellow:
        for (int i = 1; i < 4*SIZE_TILE+1; i++)
            printf(B_YELLOW_ANSI"  "RESET_ANSI);
        break;
    case green:
        for (int i = 1; i < 4*SIZE_TILE+1; i++)
            printf(B_GREEN_ANSI"  "RESET_ANSI);
        break;
    case blue:
        for (int i = 1; i < 4*SIZE_TILE+1; i++)
            printf(B_BLUE_ANSI"  "RESET_ANSI);
        break;
    default:
        printf("err print_line_houses");
        break;
    }
}

static void printTile(gameState *game, int caseNum, color_t finishColor)
{
    char *tab[2] = {" ", " "};
    switch (finishColor)
    {
    case none:
        tile_t tmp = game->b.bBoard[caseNum];
        for (int i = 0; i < 2; i++)
        { 
            if (tmp.yellowCount)
            {
                tmp.yellowCount--;
                tab[i] = y;
            }
            else if (tmp.redCount)
            {
                tmp.redCount--;
                tab[i] = r;
            }
            else if (tmp.blueCount)
            {
                tmp.blueCount--;
                tab[i] = b;
            }
            else if (tmp.greenCount)
            {
                tmp.greenCount--;
                tab[i] = g;
            }
        }
        break;

    case red:
        if (game->b.redFinishLine[caseNum].redCount == 1)
            tab[0] = r;
        if (game->b.redFinishLine[caseNum].redCount == 2)
            tab[1] = r;
        break ;
    case yellow:
        if (game->b.redFinishLine[caseNum].yellowCount == 1)
            tab[0] = y;
        if (game->b.redFinishLine[caseNum].yellowCount == 2)
            tab[1] = y;
        break ;
    case blue:
        if (game->b.redFinishLine[caseNum].blueCount == 1)
            tab[0] = b;
        if (game->b.redFinishLine[caseNum].blueCount == 2)
            tab[1] = b;
        break ;
    case green:
        if (game->b.redFinishLine[caseNum].greenCount == 1)
            tab[0] = g;
        if (game->b.redFinishLine[caseNum].greenCount == 2)
            tab[1] = g;
        break ;
    default:
        break;
    }
    printf(" %s%s ", tab[0], tab[1]);
}

void printLineHouses(color_t house1, color_t house2, gameState *game, int lineNum)
{
    //printf(RESET_ANSI"+----+----+----+");
    //int table[16][3] = {
    //    {0, 67, 66}, {}
    //}


    colorHouse(house1);
    printf(RESET_ANSI"+----+----+----+");
    colorHouse(house2);
    printf("\n");

    colorHouse(house1);
    

    //for (int i = 0; i < 3; i++)
    // totalHorseCount(game, case) == 5 ? 
    if (lineNum < 10)
        printf(RESET_ANSI"|%-2d  "RESET_ANSI, lineNum+1);
    else printf(RESET_ANSI"|%-2d  "RESET_ANSI, lineNum+14);

    if (lineNum == 0) // première ligne
    {
        printf(RESET_ANSI"|%-2d  |"RESET_ANSI, 68);
    }
    else if (lineNum == 19) // dernière ligne
    {
        printf(RESET_ANSI"|%-2d  |"RESET_ANSI, 34);
    }
    else if (lineNum < 10)
        printf(B_YELLOW_ANSI"|    |"RESET_ANSI);
    else printf(  B_RED_ANSI"|    |"RESET_ANSI);
    

    if (lineNum < 10)
        printf(RESET_ANSI"%-2d  |", 67 - lineNum);
    else printf(RESET_ANSI"%-2d  |", 67-13 - lineNum);
    
    //printf(RESET_ANSI"|");
    

    colorHouse(house2);

    printf("\n");

    colorHouse(house1);

    printf("|");
    printTile(game, 68, none);

    if (lineNum == 0) // première ligne
    {
        printf("|");
        printTile(game, 68, none);
    }
    else if (lineNum == 19) // dernière ligne
    {
        printf("|");
        printTile(game, 34, none);
    }
    else if (lineNum < 10)
    {
        printf(B_YELLOW_ANSI "|");
        printTile(game, lineNum, yellow);
    }
    else 
    {
        printf(B_RED_ANSI"|");
        printTile(game, 17 - lineNum, red);
    }

    printf("|"RESET_ANSI);
    printTile(game, 66 - lineNum, none);
    printf("|");
    //printf(RESET_ANSI"%-2d  |", 67 - lineNum);


    colorHouse(house2);

    printf("\n"); //21+1

}



    //printf(B_BLUE_ANSI"■♞    ■■\n"B_RESET_ANSI);
    //printf(B_YELLOW_ANSI"■♞    ■■\n");
    //printf(B_RED_ANSI"■♞    ■■\n"B_RESET_ANSI);
    //printf(B_GREEN_ANSI"■♞    ■■\n"B_RESET_ANSI);
    //printf(RESET_ANSI"\n");

void printBoard(gameState *game)
{

    /*printf(B_YELLOW_ANSI"  "RESET_ANSI);
    for (int i = 1; i < 4*SIZE_TILE; i++)
    {
        if (i-1 < game->b.yellowHouse)
        {
            printf("%s ", y);
        }
        else printf(B_YELLOW_ANSI"  "RESET_ANSI);
    }


    
    printf(B_GREEN_ANSI"  "RESET_ANSI);
    for (int i = 1; i < 4*SIZE_TILE; i++)
    {
        if (i-1 < game->b.greenHouse)
        {
            printf("%s ", g);
        }
        else printf(B_GREEN_ANSI"  "RESET_ANSI);
    }*/


    for (int i = 0; i < 8; i++)
        printLineHouses(yellow, green, game, i);
    colorHouse(yellow);
    printf(RESET_ANSI"+----+----+----+");
    colorHouse(green);
    printf("\n");
    printf("\n");
    for (int i = 12; i < 20; i++)
        printLineHouses(blue, red, game, i);
    colorHouse(blue);
    printf(RESET_ANSI"+----+----+----+");
    colorHouse(red);
    printf("\n");
    

    

    printf("\n"); //21+1



}