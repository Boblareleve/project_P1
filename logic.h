#ifndef __LOGIC_H__
#define __LOGIC_H__

#include "board.h"

typedef struct {
	int numPlayers;
	color_t curPlayer;
	board_t b;
	
} gameState;

void initGameState(gameState*);
color_t nextPlayer(gameState*);
int diceRoll();

#endif
