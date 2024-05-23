#ifndef __PLATEAU_H__
#define __PLATEAU_H__

typedef char horse_t;

#define BOARD_SIZE 68
#define HOUSE_SIZE (BOARD_SIZE / 4)

#define YELLOW_HOUSE 

#define FOUR_COLORS(type, name) \
	type yellow##name; \
	type blue##name; \
	type red##name; \
	type green##name; \

typedef enum {
	none = ' ',
	yellow = 'y',
	blue = 'b',
	red = 'r',
	green = 'g'
} color_t;

typedef struct {
	FOUR_COLORS(int, Count)
} tile_t;


typedef struct {
	union {
		struct {
			FOUR_COLORS(tile_t, Zone[HOUSE_SIZE])
		} houses;
		tile_t bBoard[BOARD_SIZE];
	};


	FOUR_COLORS(int, House)
	FOUR_COLORS(int, Finish)
} board_t;

int isRefuge(board_t, int pos);
color_t barrageAtPos(board_t, int pos);

// Fait en sorte que la position reste entre 0 et BOARD_SIZE
int wrapAroundPos(int pos);
// Retourne la couleur du potentiel cheval mangé
color_t isMovePossible(board_t, int startPos, int diceRoll, color_t curHorseColor);

#endif
