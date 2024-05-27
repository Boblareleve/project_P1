

#ifndef __PRINT_H__
#define __PRINT_H__


#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define B_BLUE_ANSI "\e[44m"
#define B_YELLOW_ANSI "\e[43m"
#define B_RED_ANSI "\e[41m"
#define B_GREEN_ANSI "\e[42m"

#define RED_ANSI "\e[31m"
#define GREEN_ANSI "\e[32m"
#define YELLOW_ANSI "\e[33m"
#define BLUE_ANSI "\e[34m"

#define RESET_ANSI "\e[0m"

#define WHITE "\e[47m"


#define USE_ANSI


#define SIZE_TILE 9


void printBoard(gameState *game);


#endif