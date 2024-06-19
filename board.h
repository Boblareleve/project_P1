#ifndef __PLATEAU_H__
#define __PLATEAU_H__

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef char horse_t;

#define BOARD_SIZE 68
#define HOUSE_SIZE (BOARD_SIZE / 4)
//définit les parametres du plateau
#define FOUR_COLORS(type, name) \
	type yellow##name; \
	type blue##name; \
	type red##name; \
	type green##name; \

// Définit les couleurs
typedef enum {
	none = ' ',
	yellow = 'y',
	blue = 'b',
	red = 'r',
	green = 'g'
} color_t;

// Définit les cases du plateau
typedef struct {
	FOUR_COLORS(int, Count)
} tile_t;

// Définit le plateau
typedef struct {
	union {
		struct {
			FOUR_COLORS(tile_t, Zone[HOUSE_SIZE])
		} houseBoard;
		tile_t bBoard[BOARD_SIZE];
	};

	// old version -> FOUR_COLORS(tile_t, FinishLine[7])
	// rouge de la structure représente les cases rouges...
	tile_t finishLine[7]; 

	union {
		struct {
			FOUR_COLORS(int, House)
		};
		int houses[4];
	};
	union {
		struct {
			FOUR_COLORS(int, Finish)
		};
		int finishes[4];
	};
} board_t;


// Indique le nombre de cheval de cette couleur sur cette tuile
int horseColorInTile(board_t, int pos, color_t);

// Indique si la case est l'entrer de la ligne de fin pour cette couleur
bool finishEntrence(int pos, color_t);

// Indique si la case est un refuge (indépendant de l'état du jeu)
int isRefuge(int pos);
// Indique si il y a un barrage à la position donnée
color_t barrageAtPos(board_t, int pos);
// Retourne 1 si le cheval est devant l'escalier de sa couleur, 0 sinon
int inFrontOfStairs(color_t horse, int pos);

// Retourne le nombre total de chevaux à une case donnée
int totalHorseCount(board_t, int pos);
// Cette fonction doit être appelée uniquement dans le cas où totalHorseCount(pos) <= 1 !!
color_t getSingleHorseAt(board_t, int pos);
// Fait en sorte que la position reste entre 0 et BOARD_SIZE
int wrapAroundPos(int pos);
// Retourne la couleur du potentiel cheval mangé, ou -1 si le coup ne peut pas être joué
// barrageShouldBeCreated retourne 1 si un barrage doit être créé à la position finale
// entersFinalLineAt retourne la position à laquelle le cheval entre dans la dernière ligne, 0 si il ne rentre pas dans la dernière ligne
color_t isMovePossible(board_t, int startPos, int diceRoll, color_t curHorseColor, int* barrageShouldBeCreated, int* entersFinalLineAt);



#endif
