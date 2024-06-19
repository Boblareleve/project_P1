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
    sleep(0.5);

#ifndef CHEAT 
    int result = rand()%6+1;
#endif
#ifdef CHEAT
    int result = getInput(integer, "valeur du dé (1,6) :");
#endif
    printf("Le nombre obtenu: %d\n",result);
    return result;,;
}   aaaaaaaaaaaxAAAAvRF4FT5+GHHHHHHHHHHHHHHHHHHHHHLO20J°L.YU/BBBBBBBBBBBB%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%98885R42221E3WWWWWWWw

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

void eatNotThisColor(gameState *game, int pos, color_t c) {

    if (game->b.bBoard[pos].yellowCount == 1 && c != yellow) {
        game->b.bBoard[pos].yellowCount = 0;
        game->b.yellowHouse++;
    }
    else if (game->b.bBoard[pos].redCount == 1 && c != red) {
        game->b.bBoard[pos].redCount = 0;
        game->b.redHouse++;
    }
    else if (game->b.bBoard[pos].blueCount == 1 && c != blue) {
        game->b.bBoard[pos].blueCount = 0;
        game->b.blueHouse++;
    }
    else if (game->b.bBoard[pos].greenCount == 1 && c != green) {
        game->b.bBoard[pos].greenCount = 0;
        game->b.greenHouse++;
    }
}
                    

// retourne si le mouvement est valide
bool pushPlayer(gameState *game, int pos, color_t c) {

    int distancePush = 20; 
    if (game->b.bBoard[pos].yellowCount > 0) {
        if (c == yellow && game->b.bBoard[pos].yellowCount >= 2)
            return (false);

        while (barrageAtPos(game->b, wrapAroundPos(pos+distancePush)))
            distancePush--;
        
        game->b.bBoard[pos].yellowCount--;
        game->b.bBoard[pos].yellowCount++;   
    }
    else if (game->b.bBoard[pos].blueCount > 0) {
        if (c == blue && game->b.bBoard[pos].blueCount >= 2)
            return (false);

        while (barrageAtPos(game->b, wrapAroundPos(pos+distancePush)))
            distancePush--;

        game->b.bBoard[pos].blueCount--;
        game->b.bBoard[pos].blueCount++;   
    }
    else if (game->b.bBoard[pos].redCount > 0) {
        if (c == red && game->b.bBoard[pos].redCount >= 2)
                return (false);

        while (barrageAtPos(game->b, wrapAroundPos(pos+distancePush)))
            distancePush--;
        
        game->b.bBoard[pos].redCount--;
        game->b.bBoard[pos].redCount++;
    }
    else if (game->b.bBoard[pos].greenCount > 0) {
        if (c == green && game->b.bBoard[pos].greenCount >= 2)
                return (false);

        while (barrageAtPos(game->b, wrapAroundPos(pos+distancePush)))
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
        int choice = getInput(integer, "choisit la case du pion que tu veux jouer : ")-1;



        if (!horseColorInTile(game->b, choice, game->curPlayer)) {
            printf("tu n'as pas de pion sur cette case\n");
            valideTile = false;
        }
        else {
            // barrage sur le chemin ? + départ de finish
            int barrage = 0;
            int i = choice+1;
            while (i <= choice + dice) {
                
                if (finishEntrence(wrapAroundPos(i), game->curPlayer)) {
                    barrage = -1;
                    break;
                }

                barrage += barrageAtPos(game->b, wrapAroundPos(i)) != game->curPlayer
                        && barrageAtPos(game->b, wrapAroundPos(i)) != none;
                i++;
            }
            printf("bar %d\n", barrage);

            // arrrive sur la ligne d'arrivé
            if (barrage == -1) {
                // avancement sur la ligne de fin : choice + dice - i-1;
                switch (game->curPlayer)
                {
                case yellow:
                    printf("tu rentre sur la ligne de fin !\n");
                    game->b.bBoard[choice].yellowCount--;
                    game->b.finishLine[choice + dice - i-1].yellowCount++;
                    return (true);
                case red:
                    printf("tu rentre sur la ligne de fin !\n");
                    game->b.bBoard[choice].redCount--;
                    game->b.finishLine[choice + dice - i-1].redCount++;
                    return (true);
                case blue:
                    printf("tu rentre sur la ligne de fin !\n");
                    game->b.bBoard[choice].blueCount--;
                    game->b.finishLine[choice + dice - i-1].blueCount++;
                    return (true);
                case green:
                    printf("tu rentre sur la ligne de fin !\n");
                    game->b.bBoard[choice].greenCount--;
                    game->b.finishLine[choice + dice - i-1].greenCount++;
                    return (true);
                default:
                    printf("error");
                    return (-1);
                }
            }
            // cas d'un barrage
            if (barrage) {
                printf("barrage sur le chemin tu ne peux pas jouer ce pion\n");
                valideTile = false;
            }
            // cas de coup valide
            else {
                printf("tu t'es déplacé en %d\n", choice+dice+1);
                switch (game->curPlayer)
                {
                case yellow:
                    if (getSingleHorseAt(game->b, wrapAroundPos(choice+dice)) != yellow) {
                        eatNotThisColor(game, wrapAroundPos(choice+dice), yellow);
                    }
                    game->b.bBoard[choice].yellowCount--;
                    game->b.bBoard[wrapAroundPos(choice+dice)].yellowCount++;
                    
                    return (true);
                case red:
                    if (getSingleHorseAt(game->b, wrapAroundPos(choice+dice)) != red) {
                        eatNotThisColor(game, wrapAroundPos(choice+dice), red);
                    }
                    game->b.bBoard[choice].redCount--;
                    game->b.bBoard[wrapAroundPos(choice+dice)].redCount++;
                    return (true);
                case blue:
                    if (getSingleHorseAt(game->b, wrapAroundPos(choice+dice)) != blue) {
                        eatNotThisColor(game, wrapAroundPos(choice+dice), blue);
                    }
                    game->b.bBoard[choice].blueCount--;
                    game->b.bBoard[wrapAroundPos(choice+dice)].blueCount++;
                    return (true);
                case green:
                    if (getSingleHorseAt(game->b, wrapAroundPos(choice+dice)) != green) {
                        eatNotThisColor(game, wrapAroundPos(choice+dice), green);
                    }
                    game->b.bBoard[choice].greenCount--;
                    game->b.bBoard[wrapAroundPos(choice+dice)].greenCount++;
                    return (true);
                default:
                    printf("error");
                    break;
                }
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

    switch (game->curPlayer)
    {
    case yellow:
        // un pion à sortir ?
        if (game->b.yellowHouse == 0) {
            printf("tu n'as pas de pion à sortir\n");
            return (false);
        }
        if (totalHorseCount(game->b, 4) >= 2) {
            printf("trop de pion sur la sortie\n");
            return (false);
        }
        
        // joueur soufflé ?
        if (game->b.bBoard[4].blueCount > 0
         || game->b.bBoard[4].redCount > 0
         || game->b.bBoard[4].yellowCount > 0) {
            if (!pushPlayer(game, 4, yellow)) {
                printf("tu as déjà un jaune sur le refuge\n");
                return (false);
            }
        }
        game->b.bBoard[4].yellowCount++;
        game->b.yellowHouse--;
        printf("un pion jaune est sortie de la maison !\n");
        return (true);
    case red:
        // un pion à sortir ?
        if (game->b.redHouse == 0) {
            printf("tu n'as pas de pion à sortir\n");
            return (false);
        }
        if (totalHorseCount(game->b, 38) >= 2) {
            printf("trop de pion sur la sortie\n");
            return (false);
        }

        // joueur soufflé ?
        if (game->b.bBoard[38].blueCount > 0
         || game->b.bBoard[38].yellowCount > 0
         || game->b.bBoard[38].greenCount > 0) {
            if (!pushPlayer(game, 38, red)) {
                printf("tu as déjà un rouge sur le refuge\n");
                return (false);
            }
        }
        game->b.bBoard[38].redCount++;
        game->b.redHouse--;
        printf("un pion rouge est sortie de la maison !\n");
        return (true);
    case blue:
        // un pion à sortir ?
        if (game->b.blueHouse == 0) {
            printf("tu n'as pas de pion à sortir\n");
            return (false);
        }
        if (totalHorseCount(game->b, 21) >= 2) {
            printf("trop de pion sur la sortie\n");
            return (false);
        }
        // joueur soufflé ?
        if (game->b.bBoard[21].redCount > 0
         || game->b.bBoard[21].yellowCount > 0
         || game->b.bBoard[21].greenCount > 0) {
            if (!pushPlayer(game, 21, blue)) {
                printf("tu as déjà un bleu sur le refuge\n");
                return (false);
            }
        }
        game->b.bBoard[21].blueCount++;
        game->b.blueHouse--;
        printf("un pion bleu est sortie de la maison !\n");
        return (true);
    case green:
        // un pion à sortir ?
        if (game->b.greenHouse == 0) {
            printf("tu n'as pas de pion à sortir\n");
            return (false);
        }
        if (totalHorseCount(game->b, 55) >= 2) {
            printf("trop de pion sur la sortie\n");
            return (false);
        }
        // joueur soufflé ?
        if (game->b.bBoard[55].redCount > 0
         || game->b.bBoard[55].yellowCount > 0
         || game->b.bBoard[55].blueCount > 0) {
            if (!pushPlayer(game, 55, green)) {
                printf("tu as déjà un vert sur le refuge\n");
                return (false);
            }
        }
        game->b.bBoard[55].greenCount++;
        game->b.greenHouse--;
        printf("un pion vert est sortie de la maison !\n");
        return (true);
    
    default:
        printf("error\n");
        break;
    }
    return (true);
}

bool finishMouv(gameState *game, int dice) {
    return (false);
}

void playerChoice(gameState *game, int dice) {


    bool validMouv = true;
    do {
        areas_t zone = getInput(area, "choisit la zone du pion que tu veux bouger (m maison ; l line de fin ; p plateau) : ");
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

// renvoie -1 si pas de barrage sinon la case du barrage
int searchBarrageCurPlayer(gameState *game) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (horseColorInTile(game->b, i, game->curPlayer) == 2) {
            return (i);
        }
    }
    return (-1);
}

void play() {
    gameState game;
    initGameState(&game);
    

    do {
        printBoard(&game);

        bool cheat_debug = getInput(YesNo, "cheat :");

        if (cheat_debug) {

            game.b.yellowHouse--;
            game.b.bBoard[getInput(integer, "case :")-1].yellowCount++;
        }
        else {
            int rollValue = diceRoll(game.curPlayer, getName(&game, game.curPlayer));
            int haveABarrage = searchBarrageCurPlayer(&game);
            // force le joueur à détruire sont barrage en cas de 6
            if (rollValue == 6 && haveABarrage != -1) {
                printf("tu as un barrage tu est donc obliger de le détruire !\n");

            }
            else playerChoice(&game, rollValue);
        }


        nextPlayer(&game);
    }
    while (hasPlayerWon(&game) == none); // A remplacer plus tard
}