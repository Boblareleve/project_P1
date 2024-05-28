#ifndef __LOGIC_H__
#define __LOGIC_H__

#include "board.h"

typedef struct {
	int numPlayers;
	color_t curPlayer;
	board_t b;
	
} gameState;

//initialise le jeu
void initGameState(gameState*);

//renvoie la couleur du joueur prochain
//ordre:jaune,vert,rouge,bleu
color_t nextPlayer(gameState*);

//simule le lancé de dé
int diceRoll(char* playerName);

#endif
