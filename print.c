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
    char r[] = RED_ANSI"♞"; //RESET_ANSI;
    char b[] = BLUE_ANSI"♞";//RESET_ANSI;
    char y[] = YELLOW_ANSI"♞";//RESET_ANSI;
    char g[] = GREEN_ANSI"♞";//RESET_ANSI;
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
    caseNum--;
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
        if (game->b.finishLine[caseNum].redCount >= 1)
        {
            tab[0] = "♞";
        }
        if (game->b.finishLine[caseNum].redCount == 2)
        {
            tab[1] = "♞";
        }
        
        //printf("->%s:%s", r, tab[1]);
        break ;
    case yellow:
        if (game->b.finishLine[caseNum].yellowCount >= 1)
            tab[0] = "♞";
        if (game->b.finishLine[caseNum].yellowCount == 2)
            tab[1] = "♞";
        break ;
    case blue:
        if (game->b.finishLine[caseNum].blueCount >= 1)
            tab[0] = "♞";
        if (game->b.finishLine[caseNum].blueCount == 2)
            tab[1] = "♞";
        break ;
    case green:
        if (game->b.finishLine[caseNum].greenCount >= 1)
            tab[0] = "♞";
        if (game->b.finishLine[caseNum].greenCount == 2)
            tab[1] = "♞";
        break ;
    default:
        break;
    }
    printf(" %s%s "RESET_ANSI, tab[0], tab[1]);
}

void printPlus(color_t c)
{
    switch (c)
    {
    case yellow:
        printf(RESET_ANSI"+----"B_YELLOW_ANSI"+----+"RESET_ANSI"----+");
        break;
    case red:
        printf(RESET_ANSI"+----"B_RED_ANSI"+----+"RESET_ANSI"----+");
        break;
    case blue:
        printf(RESET_ANSI"+----"B_BLUE_ANSI"+----+"RESET_ANSI"----+");
        break;
    case green:
        printf(RESET_ANSI"+----"B_GREEN_ANSI"+----+"RESET_ANSI"----+");
        break;
    
    default:
        printf("+----+----+----+");
        break;
    }
}

void printLineHouses(color_t house1, color_t house2, gameState *game, int lineNum)
{
    //printf(RESET_ANSI"+----+----+----+");
    //int table[16][3] = {
    //    {0, 67, 66}, {}
    //}

    printf("\n");

    colorHouse(house1);
    

    //for (int i = 0; i < 3; i++)
    // totalHorseCount(game, case) == 5 ? 
    if (lineNum < 10)
        printf(RESET_ANSI"| %-2d "RESET_ANSI, lineNum+1);
    else printf(RESET_ANSI"| %-2d "RESET_ANSI, lineNum+14);

    if (lineNum == 0) // première ligne
    {
        printf(RESET_ANSI"| %-2d |"RESET_ANSI, 68);
    }
    else if (lineNum == 19) // dernière ligne
    {
        printf(RESET_ANSI"| %-2d |"RESET_ANSI, 34);
    }
    else if (lineNum < 10)
        printf(B_YELLOW_ANSI"|    |"RESET_ANSI);
    else printf(  B_RED_ANSI"|    |"RESET_ANSI);
    

    if (lineNum < 10)
        printf(RESET_ANSI" %-2d |", 67 - lineNum);
    else printf(RESET_ANSI" %-2d |", 67-13 - lineNum);
    
    //printf(RESET_ANSI"|");
    

    colorHouse(house2);

    printf("\n");

    colorHouse(house1);

    if (lineNum < 10)
    {
        printf("|");
        printTile(game, lineNum+1, none);
    }
    else
    {
        printf("|");
        printTile(game, lineNum+14, none);
    }

    if (lineNum == 0) // première ligne
    {
        printf("|");
        printTile(game, 68, none);
        printf("|");
    }
    else if (lineNum == 19) // dernière ligne
    {
        printf("|");
        printTile(game, 34, none);
        printf("|");
    }
    else if (lineNum < 10)
    {
        printf(B_YELLOW_ANSI"|");
        //printf("d %d d", lineNum);
        printTile(game, lineNum, yellow);
        printf(B_YELLOW_ANSI"|");
    }
    else 
    {
        printf(B_RED_ANSI"|");
        //printf("d %dd", 18 - lineNum);
        printTile(game, 19 - lineNum, red);
        printf(B_RED_ANSI"|");
    }

    printf(RESET_ANSI);
    if (lineNum < 10)
        printTile(game, 67 - lineNum, none);
    else printTile(game, 67-13 - lineNum, none);
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


    colorHouse(yellow);
    printPlus(none);
    colorHouse(green);
    for (int i = 0; i < 8; i++)
    {
        printLineHouses(yellow, green, game, i);
        colorHouse(yellow);
        printPlus(yellow);
        colorHouse(green);
    }
    printf("\n");
    printf("\n");
    for (int i = 12; i < 20; i++)
    {
        colorHouse(blue);
        printPlus(red);
        colorHouse(red);
        printLineHouses(blue, red, game, i);
    }
    colorHouse(blue);
    printPlus(none);
    colorHouse(red);

    printf("\n");
    

    

    printf("\n"); //21+1



}