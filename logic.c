#include "logic.h"
#include "board.h"
#include "input.h"

#include <stdio.h>
#include <string.h>

// Pour importer la fonction sleep
#include <unistd.h>

void initGameState(gameState* game)
{
    // Initialise tout le plateau à 0
    memset(&game->b, 0, sizeof(board_t));

    game->numPlayers=getInput(integer,"Saisisez le nombre de joueurs: ");
    while ((game->numPlayers<2) || (game->numPlayers>4))
    {
        printf("Erreur, nombre de joueurs invalide. Le nombre de joueurs possible est de 2 à 4\n");
        game->numPlayers=getInput(integer,"Saisisez le nombre de joueurs: ");
    }
    
    for (int i = 0; i < game->numPlayers; i++) {
        printf("Joueur %d, entrez votre nom: ", i + 1);
        scanf("%s", game->playerNames[i]);
    }

    game->curPlayer=yellow;
}

void nextPlayer(gameState* game)
{
    color_t next = none;

    switch (game->curPlayer) {
        case yellow: 
            next = blue;
        case blue:
            next = (game->numPlayers == 2) ? yellow : red;
        case red:
            next = (game->numPlayers == 3) ? yellow : green;
        case green:
            next = yellow;
    }
    game->curPlayer = next;
}

int diceRoll(char* playerName)
{
    printf("%s lance le dé...\n", playerName);
    sleep(1.5);
    
    int result = rand()%6+1;
    printf("Le nombre obtenu: %d\n",result);
    return result;
}

color_t hasPlayerWon(gameState* game) {
    board* b = &game->b;

    if (b->yellowFinish == 4) return yellow;
    if (b->blueFinish == 4) return blue;
    if (b->redFinish == 4) return red;
    if (b->greenFinish == 4) return green;

    return none;
}

void play() {
    gameState game;
    initGameState(&game);

    do {
        

        nextPlayer(&game);
    }
    while (hasPlayerWon(game) == none); // A remplacer plus tard
}