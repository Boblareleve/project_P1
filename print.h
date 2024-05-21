

#ifndef __PRINT_H__
#define __PRINT_H__


#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define B_BLUE_ANSI "\e[0;34m"
#define B_YELLOW_ANSI "\e[0;34m"
#define B_RED_ANSI "\e[0;34m"
#define B_GREEN_ANSI "\e[0;34m"

#define BLUE_ANSI "\e[34m"
#define YELLOW_ANSI "\e[34m"
#define RED_ANSI "\e[34m"
#define GREEN_ANSI "\e[34m"

#define RESET_ANSI "\e[0m"

#define USE_ANSI

void print_board();


#endif