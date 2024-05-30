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
    char r[] = "r";
    char b[] = "b";
    char y[] = "j";
    char g[] = "v";
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
            printf(B_RED_ANSI" "RESET_ANSI);
        break;
    case yellow:
        for (int i = 1; i < 4*SIZE_TILE+1; i++)
            printf(B_YELLOW_ANSI" "RESET_ANSI);
        break;
    case green:
        for (int i = 1; i < 4*SIZE_TILE+1; i++)
            printf(B_GREEN_ANSI" "RESET_ANSI);
        break;
    case blue:
        for (int i = 1; i < 4*SIZE_TILE+1; i++)
            printf(B_BLUE_ANSI" "RESET_ANSI);
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
        if (game->b.finishLine[caseNum].yellowCount >= 2)
            tab[1] = "♞";
        break ;
    case blue:
        if (game->b.finishLine[caseNum].blueCount >= 1)
            tab[0] = "♞";
        if (game->b.finishLine[caseNum].blueCount >= 2)
            tab[1] = "♞";
        break ;
    case green:
        if (game->b.finishLine[caseNum].greenCount >= 1)
            tab[0] = "♞";
        if (game->b.finishLine[caseNum].greenCount >= 2)
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

void linePlus(char *c1, char*c2, int s)
{
    printf("%s", c1);
    for (int i = 0; i < s; i++)
    {
        printf("+----");
    }
    printf("+");
    printf(RESET_ANSI);
    for (int i = 0; i < 14; i++)
        printf(" ");
    printf("%s", c2);
    for (int i = 0; i < s; i++)
    {
        printf("+----");
    }
    printf("+");
    printf(RESET_ANSI);
}

void printFinish(gameState *game, color_t c, int num)
{
    char *tab[2] = {" ", " "};
    switch (c)
    {
    case yellow:
        tab[0] = (game->b.yellowFinish >= 0+num) ? "♞" : " ";
        tab[1] = (game->b.yellowFinish >= 1+num) ? "♞" : " ";
        break;
    case red:
        tab[0] = (game->b.redFinish >= 0+num) ? "♞" : " ";
        tab[1] = (game->b.redFinish >= 1+num) ? "♞" : " ";
        break;
    case blue:
        tab[0] = (game->b.blueFinish >= 0+num) ? "♞" : " ";
        tab[1] = (game->b.blueFinish >= 1+num) ? "♞" : " ";
        break;
    case green:
        tab[0] = (game->b.greenFinish >= 0+num) ? "♞" : " ";
        tab[1] = (game->b.greenFinish >= 1+num) ? "♞" : " ";
        break;
    default:
        break;
    }
    printf(" %s%s ", tab[0], tab[1]);
}

void printBoard(gameState *game)
{

    // up part
    colorHouse(yellow);
    printPlus(none);
    colorHouse(green);
    for (int i = 0; i < 7; i++)
    {
        printLineHouses(yellow, green, game, i);
        colorHouse(yellow);
        printPlus(yellow);
        colorHouse(green);
    }
    printLineHouses(yellow, green, game, 7);

    // mid part 1
    for (int i = 0; i < 9; i++)
    {
        printf("+----");
    }
    printf(B_YELLOW_ANSI"+----+"RESET_ANSI);
    for (int i = 0; i < 9; i++)
    {
        printf("----+");
    }
    printf("\n");
    
    for (int i = 16; i >= 9; i--)
        printf("| %-2d ", i);
    printf("|");


    game->b.yellowFinish = 4;
    game->b.redFinish = 3;
    //center 1
    for (int i = 0; i < 4; i++)
        printf(" ");
    printf(B_YELLOW_ANSI"|");
    printFinish(game, yellow, 1);
    printf("|"RESET_ANSI);
    for (int i = 0; i < 4; i++)
        printf(" ");


    for (int i = 59; i >= 52; i--)
        printf("| %-2d ", i);
    printf("|");

    printf("\n");


    printf("|");
    for (int i = 16; i >= 9; i--)
    {
        printTile(game, i, none);
        printf("|");
    }

    //center 2
    for (int i = 0; i < 4; i++)
        printf(" ");
    printf(B_YELLOW_ANSI"|");
    printFinish(game, yellow, 3);
    printf("|"RESET_ANSI);
    for (int i = 0; i < 4; i++)
        printf(" ");

    printf("|");
    for (int i = 59; i >= 52; i--)
    {
        printTile(game, i, none);
        printf("|");
    }
    printf("\n");


    // finish
    printf("+----");
    printf(B_BLUE_ANSI);

    for (int i = 0; i < 7; i++)
    {
        printf("+----");
    }
    printf("+"RESET_ANSI);

    //center 3 +-+
    for (int i = 0; i < 14; i++)
        printf(" ");

    printf(B_GREEN_ANSI);
    for (int i = 0; i < 7; i++)
    {
        printf("+----");
    }
    printf("+"RESET_ANSI"----+\n");


    printf("| %-2d ", 17);
    printf(B_BLUE_ANSI);
    for (int i = 1; i < 8; i++)
    {
        //printf("| %-2d ", i);
        printf("|    ", i);
    }
    printf("|");

    //center 4
    printFinish(game, blue, 1);
    printf(RESET_ANSI);
    for (int i = 0; i < 6; i++)
        printf(" ");

    printf(B_GREEN_ANSI);
    printFinish(game, green, 1);
    for (int i = 7; i >= 1; i--)
    {
        //printf("| %-2d ", i);
        printf("|    ", i);
    }
    printf("|"RESET_ANSI);

    printf(" %-2d |", 51);
    printf("\n");
    printf("|");
    printTile(game, 17, none);


    for (int i = 1; i < 8; i++)
    {
        printf(B_BLUE_ANSI"|");
        printTile(game, i, blue);
    }
    printf(B_BLUE_ANSI"|");

    //center 5
    printFinish(game, blue, 2);
    printf(RESET_ANSI);
    for (int i = 0; i < 6; i++)
        printf(" ");
    
    printf(B_GREEN_ANSI);
    printFinish(game, green, 2);

    for (int i = 7; i >= 1; i--)
    {
        printf(B_GREEN_ANSI"|");
        printTile(game, i, green);
    }
    printf(B_GREEN_ANSI"|"RESET_ANSI);

    printTile(game, 51, none);
    printf("|");
    printf("\n");


    // mid part 1 num
    printf("+----");
    printf(B_BLUE_ANSI);

    for (int i = 0; i < 7; i++)
    {
        printf("+----");
    }

    printf("+"RESET_ANSI);
    
    //center 6 +-+
    for (int i = 0; i < 14; i++)
        printf(" ");

    printf(B_GREEN_ANSI);
    for (int i = 0; i < 7; i++)
    {
        printf("+----");
    }
    printf("+"RESET_ANSI);
    printf("----+\n");

    for (int i = 18; i < 26; i++)
        printf("| %-2d ", i);
    printf("|");

    //center 7
    for (int i = 0; i < 4; i++)
        printf(" ");
    printf(B_RED_ANSI"|");
    printFinish(game, red, 1);
    printf("|"RESET_ANSI);
    for (int i = 0; i < 4; i++)
        printf(" ");
    
    for (int i = 43; i < 51; i++)
        printf("| %-2d ", i);
    printf("|");


    printf("\n");
    // cheveau
    printf("|");
    for (int i = 18; i < 26; i++)
    {
        printTile(game, i, none);
        printf("|");
    }

    //center 8
    for (int i = 0; i < 4; i++)
        printf(" ");
    printf(B_RED_ANSI"|");
    printFinish(game, red, 3);
    printf("|"RESET_ANSI);
    for (int i = 0; i < 4; i++)
        printf(" ");

    printf("|");
    for (int i = 43; i < 51; i++)
    {
        printTile(game, i, none);
        printf("|");
    }
    printf("\n");

    
    for (int i = 0; i < 9; i++)
    {
        printf("+----");
    }
    printf(B_RED_ANSI"+----+"RESET_ANSI);
    for (int i = 0; i < 9; i++)
    {
        printf("----+");
    }


    // down part
    for (int i = 12; i < 19; i++)
    {
        printLineHouses(blue, red, game, i);
        colorHouse(blue);
        printPlus(red);
        colorHouse(red);
    }
    printLineHouses(blue, red, game, 19);
    colorHouse(blue);
    printPlus(none);
    colorHouse(red);

    printf("\n");

}