#ifndef __PLATEAU_H__
#define __PLATEAU_H__

typedef char horse_t;

#define BOARD_SIZE 68
#define HOUSE_SIZE (BOARD_SIZE / 4)

#define YELLOW_HOUSE 

#define FOUR_COLORS(type, name) \
	type yellow#name; \
	type blue#name; \
	type red#name; \
	type green#name; \

typedef enum {
	none = -1,
	yellow,
	blue,
	red,
	green
} color;

typedef enum {
	none = ' ',
	yellow = 'y',
	blue = 'b',
	red = 'r',
	green = 'g'
} horse;

typedef struct {
	FOUR_COLORS(int, Count)
} tile;


typedef struct {
	union {
		struct {
			FOUR_COLORS(tile, Zone[HOUSE_SIZE])
		} houses;
		tile bBoard[BOARD_SIZE];
	};

	FOUR_COLORS(int, House)
} board;

horse getHorse(board, int pos);
horse getHorseInHouse(board, color c, int pos);
int isRefuge(board, int pos);
int isBarrage(board, int pos);

#endif
