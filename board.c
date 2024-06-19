#include "board.h"
// Définie les zones de refuge
int isRefuge(int pos) {
    return pos == 4 || pos == 11 || pos == 16 || // coin jaune
    pos == 21 || pos == 28 || pos == 33 || //  coin bleu
    pos == 38 || pos == 45 || pos == 50 || // coin rouge
    pos == 55 || pos == 62 || pos == 67; // coin vert
}
//Indique si y'a un barrage à la position pos
color_t barrageAtPos(board_t b, int pos) {
    tile_t t = b.bBoard[pos];

    if (t.yellowCount == 2) return yellow;
    if (t.blueCount == 2) return blue;
    if (t.redCount == 2) return red;
    if (t.greenCount == 2) return green;

    return none;
}
// Confirme si le cheval est devant son escalier
int inFrontOfStairs(color_t horse, int pos) {
    switch (horse) {
        case yellow: return (pos == 67);
        case blue: return (pos == 16);
        case red: return (pos == 33);
        case green: return (pos == 50);
    }
    return 0;
}
// Retourne le nombre total de chevaux sur la case pos
int totalHorseCount(board_t b, int pos) {
    tile_t t = b.bBoard[pos];
    return t.yellowCount + t.blueCount + t.redCount + t.greenCount;
}
// Dans le cas où le nombre de chevaux sur la case pos est de 1, retourne la couleur du cheval
color_t getSingleHorseAt(board_t b, int pos) {
    tile_t t = b.bBoard[pos];

    if (t.yellowCount == 1) return yellow;
    if (t.blueCount == 1) return blue;
    if (t.redCount == 1) return red;
    if (t.greenCount == 1) return green;
    else return none;
}
// Indique si la case est l'entrée de la ligne de fin de la couleur c
bool finishEntrence(int pos, color_t c)
{
    switch (c)
    {
    case yellow:
        return (pos == 67);
    case red:
        return (pos == 33);
    case blue:
        return (pos == 16);
    case green:
        return (pos == 51);
    }
    printf("error");
    return (-1);
}
// Indique s'il y a un cheval de couleur c sur la case pos
int horseColorInTile(board_t b, int pos, color_t c) {
    switch (c)
    {
    case yellow:
        return (b.bBoard[pos].yellowCount);
    case red:
        return (b.bBoard[pos].redCount);
    case blue:
        return (b.bBoard[pos].blueCount);
    case green:
        return (b.bBoard[pos].greenCount);
    }
    return (-1);
}
// Controle pour que la position reste dans les limites du plateau (0-BOARD_SIZE)
int wrapAroundPos(int pos) {
    return pos % (BOARD_SIZE);
}

color_t isMovePossible(board_t b, int startPos, int diceRoll, color_t curHorseColor, int* barrageShouldBeCreated, int* entersFinalLineAt) {
    int curPos = startPos;
    int endPos = wrapAroundPos(startPos + diceRoll);
    tile_t curTile;
    int total;

    *barrageShouldBeCreated = 0;
    *entersFinalLineAt = 0;

    while (curPos != endPos) {
        curTile = b.bBoard[curPos];
        total = totalHorseCount(b, curPos);

        if (total == 2 && barrageAtPos(b, curPos)) break;

        if (inFrontOfStairs(curHorseColor, curPos) && curPos != endPos) {
            // Le cheval est devant son escalier et doit avancer dedans
            *entersFinalLineAt = endPos - curPos; // Le nombre de pas restants
            return none;
        }

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