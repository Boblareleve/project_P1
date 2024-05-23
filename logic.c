#include "logic.h"
#include <stdio.h>
#include <stdio.h>
#include <time.h>
#include <board.h>


void initGameState(gameState* game)
{
    game.numPlayers=getInput(int,"Saisisez le nombre de joueurs");
    while ((game->numPlayers<2) || (game->numPlayers>4))
    {
        printf("Erreur, nombre de joueurs invalide. Le nombre de joueurs possible est de 2 à 4\n");
        game->numPlayers=getInput(int,"Saisisez le nombre de joueurs");
    }
    game->curPlayer='b';
    for(int i=0;i<BOARD_SIZE;i++)
    {
        game->b.bBoard[i].yellowCount=0;
        game->b.bBoard[i].greenCount=0;
        game->b.bBoard[i].blueCount=0;
        game->b.bBoard[i].redCount=0;
    }
    for (int i=0;i<7;i++)
    {
        game->b.yellowfinishLine[i].yellowCount=0;
        game->b.yellowfinishLine[i].greenCount=0;
        game->b.yellowfinishLine[i].redCount=0;
        game->b.yellowfinishLine[i].blueCount=0;
        game->b.bluefinishLine[i].blueCount=0;
        game->b.bluefinishLine[i].greenCount=0;
        game->b.bluefinishLine[i].redCount=0;
        game->b.bluefinishLine[i].yellowCount=0;
        game->b.greenfinishLine[i].yellowCount=0;
        game->b.greenfinishLine[i].redCount=0;
        game->b.greenfinishLine[i].greenCount=0;
        game->b.greenfinishLine[i].blueCount=0;
        game->b.redfinishLine[i].blueCount=0;
        game->b.redfinishLine[i].greenCount=0;
        game->b.redfinishLine[i].redCount=0;
        game->b.redfinishLine[i].yellowCount=0;
    }

}
color_t nextPlayer(gameState* player)
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

