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

static void printTile(gameState *game, int caseNum, bool finishColor)
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
        if (game->b.redFinishLine[caseNum] == 1)
            tab[0] = r;
        if (game->b.redFinishLine[caseNum] == 2)
            tab[1] = r;
        break ;
    case yellow:
        if (game->b.redFinishLine[caseNum] == 1)
            tab[0] = y;
        if (game->b.redFinishLine[caseNum] == 2)
            tab[1] = y;
        break ;
    case blue:
        if (game->b.redFinishLine[caseNum] == 1)
            tab[0] = b;
        if (game->b.redFinishLine[caseNum] == 2)
            tab[1] = b;
        break ;
    case green:
        if (game->b.redFinishLine[caseNum] == 1)
            tab[0] = g;
        if (game->b.redFinishLine[caseNum] == 2)
            tab[1] = g;
        break ;
    default:
        break;
    }
    printf(" %s %s ", tab[0], tab[1]);
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
    printf(RESET_ANSI"|%-2d   ", lineNum+1);

    if (lineNum == 0) // première ligne
    {
        printf(RESET_ANSI"|%-2d   |", 68);
    }
    else if (lineNum == 18) // dernière ligne
    {
        printf(RESET_ANSI"|%-2d   |", 34);
    }
    else if (lineNum < 10)
        printf(B_YELLOW_ANSI"|     |");
    else printf(  B_RED_ANSI"|     |");
    

    printf(RESET_ANSI"%-2d   |", 67 - lineNum);
    
    //printf(RESET_ANSI"|");
    

    colorHouse(house2);

    printf("\n");

    colorHouse(house1);

    //for (int i = 0; i < 8*SIZE_TILE; i++)
    //{
    //    printf(B_YELLOW_ANSI" "RESET_ANSI);
    //}

    //printf(RESET_ANSI"| %s %s ", r,r);
    //printf(RESET_ANSI"| %s %s ", r,r);
    //printf(RESET_ANSI"| %s %s ", r,r);
    //printf(RESET_ANSI"|");

    printTile(game, 68, lineNum, none);

    if (lineNum == 0) // première ligne
    {
        printTile(game, 68, none);
    }
    else if (lineNum == 18) // dernière ligne
    {
        printTile(game, 34, none);
    }
    else if (lineNum < 10)
    {
        printf(B_YELLOW_ANSI);
        printTile(game, lineNum, yellow);
    }
    else 
    {
        printf(B_RED_ANSI);
        printTile(game, 17 - lineNum, red);
    }

    printTile(game, 66 - lineNum, none);
    //printf(RESET_ANSI"%-2d  |", 67 - lineNum);


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
    

    
    printLineHouses(yellow, green, game, 0);
    

    

    printf("\n"); //21+1



}