#include "logic.h"
#include <stdio.h>
#include <stdio.h>
#include <time.h>


void initGameState(gameState* game)
{
    game.numPlayers=getInput(int,"Saisisez le nombre de joueurs");
    while ((game.numPlayers<2) || (game.numPlayers>4))
    {
        printf("Erreur, nombre de joueurs invalide. Le nombre de joueurs possible est de 2 à 4\n");
        game.numPlayers=getInput(int,"Saisisez le nombre de joueurs");
    }
    game.curPlayer='b';


}
color nextPlayer(gameState* player)
{
    
}

int diceRoll()
{
    srand(time(NULL));
    getInput(YesNo,"Voulez-vous lancer le dé?");
    int result=rand()%6+1;
    printf("Le nombe obtenu: %d\n",result);
    return result;
}

