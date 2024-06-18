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

/*
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
#endif*/

void printColor(color_t c)
{
    switch (c)
    {
    case yellow:
        printf("jaune");
        return ;
    case red:
        printf("rouge");
        return ;
    case blue:
        printf("bleu");
        return ;
    case green:
        printf("vert");
        return ;
    }
    printf("[bug]");
}

static void interTile()
{
    printf("+");
    for (int i = 0; i < SIZE_TILE; i++)
        printf("-");
}

void printHouseTile(gameState *game, color_t c, bool numRow)
{
    char *tab[] = {" ", " "};
    switch (c)
    {
    case yellow:
        if (numRow)
        {
            if (game->b.yellowHouse >= 3)
                tab[0] = YELLOW_ANSI"♞";
            if (game->b.yellowHouse >= 4)
                tab[1] = YELLOW_ANSI"♞";
        }
        else
        {
            if (game->b.yellowHouse >= 1)
                tab[0] = YELLOW_ANSI"♞";
            if (game->b.yellowHouse >= 2)
                tab[1] = YELLOW_ANSI"♞";
        }
        break;
    case red:
        if (numRow)
        {
            if (game->b.redHouse >= 3)
                tab[0] = RED_ANSI"♞";
            if (game->b.redHouse >= 4)
                tab[1] = RED_ANSI"♞";
        }
        else
        {
            if (game->b.redHouse >= 1)
                tab[0] = RED_ANSI"♞";
            if (game->b.redHouse >= 2)
                tab[1] = RED_ANSI"♞";
        }
        break;
    case blue:
        if (numRow)
        {
            if (game->b.blueHouse >= 3)
                tab[0] = BLUE_ANSI"♞";
            if (game->b.blueHouse >= 4)
                tab[1] = BLUE_ANSI"♞";
        }
        else
        {
            if (game->b.blueHouse >= 1)
                tab[0] = BLUE_ANSI"♞";
            if (game->b.blueHouse >= 2)
                tab[1] = BLUE_ANSI"♞";
        }
        break;
    case green:
        if (numRow)
        {
            if (game->b.greenHouse >= 3)
                tab[0] = GREEN_ANSI"♞";
            if (game->b.greenHouse >= 4)
                tab[1] = GREEN_ANSI"♞";
        }
        else
        {
            if (game->b.greenHouse >= 1)
                tab[0] = GREEN_ANSI"♞";
            if (game->b.greenHouse >= 2)
                tab[1] = GREEN_ANSI"♞";
        }
        break;
    default:
        printf("err color\n");
        break;
    }
    printf("  %s%s  "RESET_ANSI, tab[0], tab[1]);
}

void colorHouse(gameState *game, color_t house, int numLine, bool left)
{
    //printf("(%02d)", numLine);

    if (numLine >= 10 && numLine < 14
     || numLine >= 47 && numLine < 51)
    {
        switch (house)
        {
        case red:
            for (int i = 0; i < 17; i++) //4*SIZE_TILE+1; i++)
                printf(B_RED_ANSI" "RESET_ANSI);
            if (numLine >= 48 && numLine < 50)
                printHouseTile(game, red, numLine-48);    
            else printf("      ");
            for (int i = 0; i < 17; i++) //4*SIZE_TILE+1; i++)
                printf(B_RED_ANSI" "RESET_ANSI);

            break;
        case yellow:
            for (int i = 0; i < 17; i++) //4*SIZE_TILE+1; i++)
                printf(B_YELLOW_ANSI" "RESET_ANSI);
            if (numLine >= 11 && numLine < 13)
                printHouseTile(game, yellow, numLine-11);    
            else printf("      ");
            
            for (int i = 0; i < 17; i++) //4*SIZE_TILE+1; i++)
                printf(B_YELLOW_ANSI" "RESET_ANSI);
            //for (int i = 1; i < 4*SIZE_TILE+1; i++)
            break;
        case green:
            for (int i = 0; i < 17; i++) //4*SIZE_TILE+1; i++)
                printf(B_GREEN_ANSI" "RESET_ANSI);
            
            if (numLine >= 11 && numLine < 13)
                printHouseTile(game, green, numLine-11);    
            else printf("      ");

            for (int i = 0; i < 17; i++) //4*SIZE_TILE+1; i++)
                printf(B_GREEN_ANSI" "RESET_ANSI);
            //for (int i = 1; i < 4*SIZE_TILE+1; i++)
            break;
        case blue:
            for (int i = 0; i < 17; i++) //4*SIZE_TILE+1; i++)
                printf(B_BLUE_ANSI" "RESET_ANSI);
            
            if (numLine >= 48 && numLine < 50)
                printHouseTile(game, blue, numLine-48);    
            else printf("      ");
            
            for (int i = 0; i < 17; i++) //4*SIZE_TILE+1; i++)
                printf(B_BLUE_ANSI" "RESET_ANSI);
            //for (int i = 1; i < 4*SIZE_TILE+1; i++)
            break;
        default:
            printf("err print_line_houses");
            break;
        }
    }
    else
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
    }}
}

static void printTile(gameState *game, int caseNum, color_t finishColor)
{
    caseNum--;
    char *tab[2] = {" ", " "};
    tile_t tmp;
    switch (finishColor)
    {
    case none:
        tmp = game->b.bBoard[caseNum];
        for (int i = 0; i < 2; i++)
        { 
            if (tmp.yellowCount)
            {
                tmp.yellowCount--;
                tab[i] = YELLOW_ANSI"♞";
            }
            else if (tmp.redCount)
            {
                tmp.redCount--;
                tab[i] = RED_ANSI"♞";
            }
            else if (tmp.blueCount)
            {
                tmp.blueCount--;
                tab[i] = BLUE_ANSI"♞";
            }
            else if (tmp.greenCount)
            {
                tmp.greenCount--;
                tab[i] = GREEN_ANSI"♞";
            }
        }
        break;

    case red:
        if (game->b.finishLine[caseNum].redCount >= 1)
            tab[0] = "♞";
        if (game->b.finishLine[caseNum].redCount == 2)
            tab[1] = "♞";
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

    colorHouse(game, house1, lineNum*3+1, true);
    

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
    

    colorHouse(game, house2, lineNum*3+1, false);

    printf("\n");

    colorHouse(game, house1, lineNum*3+2, true);

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


    colorHouse(game, house2, lineNum*3+2, false);
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
    colorHouse(game, yellow, 0, true);
    printPlus(none);
    colorHouse(game, green, 0, false);
    for (int i = 0; i < 7; i++)
    {
        printLineHouses(yellow, green, game, i);
        colorHouse(game, yellow, i*3+3, true);
        printPlus(yellow);
        colorHouse(game, green, i*3+3, false);
    }
    printLineHouses(yellow, green, game, 7);

    // mid part 1
    for (int i = 0; i < 9; i++)
    {
        printf("+----");
    }
    printf(B_YELLOW_ANSI"+####+"RESET_ANSI);
    for (int i = 0; i < 9; i++)
    {
        printf("----+");
    }
    printf("\n");
    
    for (int i = 16; i >= 9; i--)
        printf("| %-2d ", i);
    printf("|");


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

    //center 3 +-+
    printf("+----"RESET_ANSI"+"B_YELLOW_ANSI"----"RESET_ANSI"+"B_GREEN_ANSI"----");
    //for (int i = 0; i < 14; i++)
    //    printf(" ");

    //printf(B_GREEN_ANSI);
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
    printf("#");

    //center 4
    printFinish(game, blue, 1);

    printf("|"RESET_ANSI);

    for (int i = 0; i < 4; i++)
        printf(" ");

    printf(B_GREEN_ANSI"|");
    printFinish(game, green, 1);
    printf("#    ");
    for (int i = 6; i >= 1; i--)
    {
        //printf("| %-2d ", i);
        printf("|    ");
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
    printf(B_BLUE_ANSI"#");

    //center 5
    printFinish(game, blue, 3);
    printf("|"RESET_ANSI);
    for (int i = 0; i < 4; i++)
        printf(" ");
    
    printf(B_GREEN_ANSI"|");
    printFinish(game, green, 3);
    printf("#");
    for (int i = 7; i >= 1; i--)
    {
        printTile(game, i, green);
        printf(B_GREEN_ANSI"|");
    }
    printf(RESET_ANSI);

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

    
    //center 6 +-+
    printf("+----"RESET_ANSI"+"B_RED_ANSI"----"RESET_ANSI"+"B_GREEN_ANSI"----");

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
    printf(B_RED_ANSI"+####+"RESET_ANSI);
    for (int i = 0; i < 9; i++)
    {
        printf("----+");
    }


    // down part  23
    for (int i = 12; i < 19; i++)
    {
        printLineHouses(blue, red, game, i);
        colorHouse(game, blue, 3*i+3, true);
        printPlus(red);
        colorHouse(game, red, 3*i+3, false);
    }
    printLineHouses(blue, red, game, 19);
    colorHouse(game, blue, 19*3+3, true);
    printPlus(none);
    colorHouse(game, red, 19*3+3, false);

    printf("\n");

}