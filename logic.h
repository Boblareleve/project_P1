#ifndef __LOGIC_H__
#define __LOGIC_H__

#include "board.h"

typedef struct {
	int numPlayers;
	color_t curPlayer;
	board_t b;
	
} gameState;

// initialise le jeu
void initGameState(gameState*);

// met curPlayer à la couleur du prochain joueur
// ordre:jaune,vert,rouge,bleu
void nextPlayer(gameState*);

// simule le lancé de dé
int diceRoll(char* playerName);

// lance la partie
void play();

#endif
