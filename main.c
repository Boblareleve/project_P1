#include "main.h"




int main()
{
    //for (int i = 0; i < 19 * 9; i++)
    //    printf("#");
    //printf("\n");
    srand(time(NULL));
    printf("Bonjour bienvenue\n");

    //gameState game;
    //initGameState(&game);
    //
    //printBoard(&game);


    bool continue_play = getInput(YesNo, "Veux-tu commencer une partie ?\n");
    while (continue_play)
    {

        play();

        continue_play = getInput(YesNo, "Veux-tu rejouer une partie ?\n");
    }



    

}