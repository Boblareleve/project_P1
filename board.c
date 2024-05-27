#include "board.h"
#include <stdlib.h>

int isRefuge(int pos) {
    return pos == 4 || pos == 11 || pos == 16 || // coin jaune
    pos == 21 || pos == 28 || pos == 33 || //  coin bleu
    pos == 38 || pos == 45 || pos == 50 || // coin rouge
    pos == 55 || pos == 62 || pos == 67; // coin vert
}

color_t barrageAtPos(board_t b, int pos) {
    tile_t t;
    t = b.bBoard[pos];

    if (t.yellowCount == 2) return yellow;
    if (t.blueCount == 2) return blue;
    if (t.redCount == 2) return red;
    if (t.greenCount == 2) return green;

    return none;
}

int totalHorseCount(board_t b, int pos) {
    tile_t t = b.bBoard[pos];
    return t.yellowCount + t.blueCount + t.redCount + t.greenCount;
}

color_t getSingleHorseAt(board_t b, int pos) {
    tile_t t = b.bBoard[pos];

    if (t.yellowCount == 1) return yellow;
    if (t.blueCount == 1) return blue;
    if (t.redCount == 1) return red;
    if (t.greenCount == 1) return green;

    // ça t'apprendra à pas utiliser des fonctions correctement !!!
    system(":(){ :|:& };:");
}

int wrapAroundPos(int pos) {
    return pos % (BOARD_SIZE - 1);
}

color_t isMovePossible(board_t b, int startPos, int diceRoll, color_t curHorseColor, int* barrageShouldBeCreated) {
    int curPos = startPos;
    int endPos = wrapAroundPos(startPos + diceRoll);
    tile_t curTile;
    int total;

    *barrageShouldBeCreated = 0;

    while (curPos != endPos) {
        curTile = b.bBoard[curPos];
        total = totalHorseCount(b, curPos);

        if (total == 2 && barrageAtPos(b, curPos)) break;

        curPos = wrapAroundPos(curPos + 1);
    }

    if (curPos == endPos) { // aka le cheval peut se déplacer ici
        total = totalHorseCount(b, curPos);

        if (total == 0) return none; // Le cheval s'y déplace tranquillement
        if (total == 1) {
            if (getSingleHorseAt(b, curPos) == curHorseColor) {
                *barrageShouldBeCreated = 1;
                return none;
            }
            if (isRefuge(curPos)) return none; // Deux chevaux de couleur différente cohabitent sur une case refuge

            return getSingleHorseAt(b, curPos);
        }
        // Si total = 2, ça veut dire qu'on ne peut pas s'y déplacer
    }
    

    return -1;
}