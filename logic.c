#include "logic.h"
#include <stdio.h>
#include <stdio.h>
#include <time.h>
#include "board.h"


void initGameState(gameState* game)
{
    game->numPlayers=getInput(integer,"Saisisez le nombre de joueurs");
    while ((game->numPlayers<2) || (game->numPlayers>4))
    {
        printf("Erreur, nombre de joueurs invalide. Le nombre de joueurs possible est de 2 à 4\n");
        game->numPlayers=getInput(integer,"Saisisez le nombre de joueurs");
    }

    game->curPlayer=yellow;

    // initialise les cases principales
    for(int i = 0; i < BOARD_SIZE; i++)
    {
        game->b.bBoard[i] = {
            .yellowCount=0,
            .greenCount=0,
            .blueCount=0,
            .redCount=0,
        }
    }

    // init les lignes de fin
    // comprend 4 couleur par ligne, même si 3 inutile
    for (int i = 0;i < 7; i++)
    {
        game->b.yellowFinishLine[i].yellowCount=0;
        game->b.yellowFinishLine[i].greenCount=0;
        game->b.yellowFinishLine[i].redCount=0;
        game->b.yellowFinishLine[i].blueCount=0;
        game->b.blueFinishLine[i].blueCount=0;
        game->b.blueFinishLine[i].greenCount=0;
        game->b.blueFinishLine[i].redCount=0;
        game->b.blueFinishLine[i].yellowCount=0;
        game->b.greenFinishLine[i].yellowCount=0;
        game->b.greenFinishLine[i].redCount=0;
        game->b.greenFinishLine[i].greenCount=0;
        game->b.greenFinishLine[i].blueCount=0;
        game->b.redFinishLine[i].blueCount=0;
        game->b.redFinishLine[i].greenCount=0;
        game->b.redFinishLine[i].redCount=0;
        game->b.redFinishLine[i].yellowCount=0;
    }

}
color_t nextPlayer(gameState* player)
{
    if (player.numPlayers=4)
    {

        switch  (player->curPlayer)
        {
            case yellow:
                return green;
                break ;
            case green:
                return red;
                break;
            case red:
                return blue;
                break;
            case blue:
                return yellow;
                break;
            default:
                return none;
        }
    }
    //renvoie le joueur prochain en tenant compte que 4 personnes jouent
    if (player.numPlayers=3)
    {
        switch  (player->curPlayer)
        {
            case yellow:
                return green;
                break ;
            case green:
                return red;
                break;
            case red:
                return yellow;
                break;
            default:
                return none;
        }
    }
    //renvoie le joueur prochain en tenant compte que 3 personnes jouent
    if (player.numPlayers=2)
    {
        switch  (player->curPlayer)
        {
            case yellow:
                return green;
                break ;
            case green:
                return yellow;
                break;
            default:
                return none;
        }
    }
    //renvoie le joueur prochain en tenant compte que 2 personnes jouent
}

int diceRoll()
{
    srand(time(NULL));
    getInput(YesNo,"Voulez-vous lancer le dé?");
    int result=rand()%6+1;
    printf("Le nombe obtenu: %d\n",result);
    return result;
}

