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
            break;
        case blue:
            next = (game->numPlayers == 2) ? yellow : red;
            break;
        case red:
            next = (game->numPlayers == 3) ? yellow : green;
            break;
        case green:
            next = yellow;
            break;
    }
    game->curPlayer = next;
}

int diceRoll(color_t c,  char* playerName)
{
    printColor(c); printf(" (%s) lance le dé...\n", playerName);
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

char *getName(gameState *game, color_t c) {
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



// retourne si le mouvement est valide
bool pushPlayer(gameState *game, int pos, color_t c) {

    int distancePush = 20; 
    if (game->b.bBoard[pos].yellowCount > 0) {
        if (c == yellow && game->b.bBoard[pos].yellowCount >= 2)
            return (false);

        while (barrageAtPos(game->b, pos+distancePush))
            distancePush--;
        
        game->b.bBoard[pos].yellowCount--;
        game->b.bBoard[pos].yellowCount++;   
    }
    else if (game->b.bBoard[pos].blueCount > 0) {
        if (c == blue && game->b.bBoard[pos].blueCount >= 2)
            return (false);

        while (barrageAtPos(game->b, pos+distancePush))
            distancePush--;

        game->b.bBoard[pos].blueCount--;
        game->b.bBoard[pos].blueCount++;   
    }
    else if (game->b.bBoard[pos].redCount > 0) {
        if (c == red && game->b.bBoard[pos].redCount >= 2)
                return (false);

        while (barrageAtPos(game->b, pos+distancePush))
            distancePush--;
        
        game->b.bBoard[pos].redCount--;
        game->b.bBoard[pos].redCount++;
    }
    else if (game->b.bBoard[pos].greenCount > 0) {
        if (c == green && game->b.bBoard[pos].greenCount >= 2)
                return (false);

        while (barrageAtPos(game->b, pos+distancePush))
            distancePush--;
        
        game->b.bBoard[pos].greenCount--;
        game->b.bBoard[pos].greenCount++;
    }
    return (true);
}

bool boardMouv(gameState *game, int dice) {
    bool valideTile = true;
    do
    {
        // getInput()-1 pour récupèrer l'indice
        int choice = getInput(integer, "choisit la case du pion que tu veux jouer :\n")-1;
        


        if (!horseColorInTile(game->b, choice, game->curPlayer)) {
            printf("tu n'as pas de pion sur cette case\n");
            valideTile = false;
        }
        else
        {

        }
         if (barrageAtPos(game->b, wrapAroundPos(choice + dice)) != game->curPlayer
              && barrageAtPos(game->b, wrapAroundPos(choice + dice)) != none) {
            printf("barrage sur le chemin tu ne peux pas jouer ce pion\n");
            valideTile = false;
        }
        else {
            // barrage sur le chemin ?
            bool barrage = false;
            for (int i = choice+1; i <= choice + dice; i++) {
                
                if (finishEntrence(i, game->curPlayer)) {

                }

                barrage += barrageAtPos(game->b, wrapAroundPos(i)) != game->curPlayer
                        && barrageAtPos(game->b, wrapAroundPos(i)) != none;
            }
            if (barrage) {
                printf("barrage sur le chemin tu ne peux pas jouer ce pion\n");
                valideTile = false;
            }
            else {
                
            }
        }

    } while (!valideTile);

    return (true);
        
}

bool houseMouv(gameState *game, int dice) {
    // peut sortir ?
    if (dice != 6) {
        printf("zone non valide tu n'as pas fait un 6\n");
        // joueur ne peux rien jouer d'autre ?
        switch (game->curPlayer)
        {
        case yellow:
            if (game->b.yellowHouse == 4 - game->b.yellowFinish) {
                printf("tu passe ton tour\n");
                return (true);
            }
            break;
        case red:
            if (game->b.redHouse == 4 - game->b.redFinish) {
                printf("tu passe ton tour\n");
                return (true);
            }
            break;
        case blue:
            if (game->b.blueHouse == 4 - game->b.blueFinish) {
                printf("tu passe ton tour\n");
                return (true);
            }
            break;
        case green:
            if (game->b.greenHouse == 4 - game->b.greenFinish) {
                printf("tu passe ton tour\n");
                return (true);
            }
            break;
        
        default:
            printf("error");
            break;
        }
        return (false);
    }
    bool validMouv = true;
    switch (game->curPlayer)
    {
    case yellow:
        // un pion à sortir ?
        if (game->b.yellowHouse == 0) {
            validMouv = false;
            printf("zone non valide tu n'as pas de pion à sortir\n");
                printf("zone non valide tu as déjà un jaune sur le refuge\n");
            break;
        }
        
        // joueur soufflé ?
        if (game->b.bBoard[4].blueCount > 0
         || game->b.bBoard[4].redCount > 0
         || game->b.bBoard[4].greenCount > 0) {
            if (!pushPlayer(game, 4, yellow)) {
                validMouv = false;
                printf("zone non valide tu as déjà un jaune sur le refuge\n");
                break;
            }
        }
        game->b.bBoard[4].yellowCount++;
        game->b.yellowHouse--;
        printf("un pion jaune est sortie de la maison !\n");
        break;
    case red:
        // un pion à sortir ?
        if (game->b.redHouse == 0) {
            validMouv = false;
            printf("zone non valide tu n'as pas de pion à sortir\n");
            break;
        }

        // joueur soufflé ?
        if (game->b.bBoard[38].blueCount > 0
         || game->b.bBoard[38].yellowCount > 0
         || game->b.bBoard[38].greenCount > 0) {
            if (!pushPlayer(game, 38, red)) {
                validMouv = false;
                printf("zone non valide tu as déjà un rouge sur le refuge\n");
                break;
            }
        }
        game->b.bBoard[38].redCount++;
        game->b.redHouse--;
        printf("un pion rouge est sortie de la maison !\n");
        break;
    case blue:
        // un pion à sortir ?
        if (game->b.blueHouse == 0) {
            validMouv = false;
            printf("zone non valide tu n'as pas de pion à sortir\n");
            break;
        }
        // joueur soufflé ?
        if (game->b.bBoard[21].redCount > 0
         || game->b.bBoard[21].yellowCount > 0
         || game->b.bBoard[21].greenCount > 0) {
            if (!pushPlayer(game, 21, blue)) {
                validMouv = false;
                printf("zone non valide tu as déjà un bleu sur le refuge\n");
                break;
            }
        }
        game->b.bBoard[21].blueCount++;
        game->b.blueHouse--;
        printf("un pion bleu est sortie de la maison !\n");
        break;
    case green:
        // un pion à sortir ?
        if (game->b.greenHouse == 0) {
            validMouv = false;
            printf("zone non valide tu n'as pas de pion à sortir\n");
            break;
        }
        // joueur soufflé ?
        if (game->b.bBoard[55].redCount > 0
         || game->b.bBoard[55].yellowCount > 0
         || game->b.bBoard[55].blueCount > 0) {
            if (!pushPlayer(game, 55, green)) {
                validMouv = false;
                printf("zone non valide tu as déjà un vert sur le refuge\n");
                break;
            }
        }
        game->b.bBoard[55].greenCount++;
        game->b.greenHouse--;
        printf("un pion vert est sortie de la maison !\n");
        break;
    
    default:
        printf("error\n");
        break;
    }
    return (validMouv);
}

bool finishMouv(gameState *game, int dice) {
    return (false);
}

void playerChoice(gameState *game, int dice) {


    bool validMouv = true;
    do {
        areas_t zone = getInput(area, "choisit la zone du pion que tu veux bouger (m maison ; l line de fin ; p plateau) :\n");
        color_t tmp_color;


        // sort de la maison
        if (zone == 'm') {
            validMouv = houseMouv(game, dice);
        }
        // bouge sur le plateau
        else if (zone == 'p') {
            validMouv = boardMouv(game, dice);
        }
        // bouge sur la ligne de fin
        else if (zone == 'l') {
            validMouv = finishMouv(game, dice);
        }
        else printf("error\n");
        
    } while (!validMouv);
    
}


void play() {
    gameState game;
    initGameState(&game);
    

    do {
        printBoard(&game);
        playerChoice(&game, 
            diceRoll(game.curPlayer,
                getName(&game, game.curPlayer)
            )
        );

        nextPlayer(&game);
    }
    while (hasPlayerWon(&game) == none); // A remplacer plus tard
}