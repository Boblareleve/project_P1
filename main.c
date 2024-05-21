#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "input.h"
#include "print.h"


/*
typedef struct {
        int a;
        int b;
        int c;
    } d;

    d papapapapa = {
        1,
        1,
        1,
    }*/



int main()
{
    print_board();


    printf(BLUE_ANSI"Bonjour bienvenu\n"RESET_ANSI);

    bool continue_play = false; 
    char input[10];
    do
    {
        get_input(YesNo, "commencer une partie ? (yes/no)\n");
        

    } while (continue_play);
    

}