#ifndef __LOGIC_H__
#define __LOGIC_H__

#include "board.h"

typedef struct {
	int numPlayers;
	color curPlayer;
	board b;
} gameState;

void initGameState(gameState*);
color nextPlayer(gameState*);

int diceRoll();

#endif
