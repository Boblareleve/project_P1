#ifndef __LOGIC_H__
#define __LOGIC_H__

#include "board.h"

typedef struct {
	int numPlayers;
	color_t curPlayer;
	board_t b;
	
} gameState;

void initGameState(gameState*);
//initialise le jeu
color_t nextPlayer(gameState*);
//renvoie la couleur du joueur prochain
//ordre:jaune,vert,rouge,bleu
int diceRoll();
//simule le lancé de dé

#endif
