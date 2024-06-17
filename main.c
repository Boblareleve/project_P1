#include "main.h"




int main()
{
    //for (int i = 0; i < 19 * 9; i++)
    //    printf("#");
    //printf("\n");
    srand(time(NULL));
    gameState game;
    initGameState(&game);

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