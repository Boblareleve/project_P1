#ifndef __LOGIC_H__
#define __LOGIC_H__

#include "board.h"

typedef struct {
	int numPlayers;
	char playerNames[100][4];
	color_t curPlayer;
	board_t b;
	
} gameState;


typedef enum {
	house='m',
	finishLine='l',
	finish='f',
	mainBoard='p'
} areas_t;

// initialise le jeu
void initGameState(gameState*);

// met curPlayer à la couleur du prochain joueur
// ordre:jaune,vert,rouge,bleu
void nextPlayer(gameState*);

// simule le lancé de dé
int diceRoll(color_t, char* playerName);

//
color_t hasPlayerWon(gameState*);

// lance la partie
void play();

#endif
