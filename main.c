#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "input.h"
#include "print.h"
#include "logic.h"
#include "board.h"


/*
typedef struct {
        int a;
        int b;
        int c;
    } d;

    d papapapapa = {
        1,
        1,
        1,
    }*/



int main()
{
    //for (int i = 0; i < 19 * 9; i++)
    //    printf("#");
    //printf("\n");
    gameState game;
    printBoard(&game);
    return (1);

    printf("Bonjour bienvenu\n");

    bool continue_play = false; 
    char input[10];
    do
    {
        getInput(YesNo, "commencer une partie ? (yes/no)\n");
        

    } while (continue_play);
    

}