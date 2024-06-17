#include "logic.h"
#include "board.h"
#include "input.h"
#include "print.h"

#include <stdio.h>
#include <string.h>

// Pour importer la fonction sleep
#include <unistd.h>

void initGameState(gameState* game)
{
    // Initialise tout le plateau à 0
    memset(&game->b, 0, sizeof(board_t));
    memset(&(game->b.finishLine), 0, sizeof(tile_t) * 7);

    game->numPlayers = getInput(integer,"Saisisez le nombre de joueurs: ");
    while ((game->numPlayers < 2) || (game->numPlayers > 4)) {
        printf("Erreur, nombre de joueurs invalide. Le nombre de joueurs possible est de 2 à 4\n");
        game->numPlayers = getInput(integer,"Saisisez le nombre de joueurs: ");
    }
    
    memset(&(game->b.houses), 0, sizeof(int) * 4);


    printf("Joueur jaune, entrez votre nom: ");
    scanf("%99s", game->playerNames[0]); // 0 -> jaune
    game->b.yellowHouse = 4;

    printf("Joueur bleu, entrez votre nom: ");
    scanf("%99s", game->playerNames[1]); // 1 -> bleu
    game->b.blueHouse = 4;

    if (game->numPlayers > 2) {
        printf("Joueur rouge, entrez votre nom: ");
        scanf("%99s", game->playerNames[2]); // 1 -> rouge
        game->b.redHouse = 4;

        if (game->numPlayers > 3)
            game->b.greenHouse = 4;
            printf("Joueur vert, entrez votre nom: ");
            scanf("%99s", game->playerNames[3]); // 1 -> vert
    }
    memset(&(game->b.finishes), 0, sizeof(int) * 4);


    game->curPlayer = yellow;
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
    board_t* b = &(game->b);

    if (b->yellowFinish == 4) return yellow;
    if (b->blueFinish == 4) return blue;
    if (b->redFinish == 4) return red;
    if (b->greenFinish == 4) return green;

    return none;
}

char *getName(color_t c)
{
    switch (c)
    {
    case yellow:
        return (game->playerNames[0]);
    case blue:
        return (game->playerNames[1]);
    case red:
        return (game->playerNames[2]);
    case green:
        return (game->playerNames[3]);
    }
    return (NULL);
}



void play() {
    gameState game;
    initGameState(&game);
    int 

    do {
        printColor(game->curPlayer);
        printf(" à lance le dé\n");
        scanf("");
        diceRoll(getName(game->curPlayer));

        
        

        nextPlayer(&game);
    }
    while (hasPlayerWon(&game) == none); // A remplacer plus tard
}