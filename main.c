#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "input.h"

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


    printf("Bonjour bienvenu\n");

    bool continue_play = false; 
    char input[10];
    do
    {
        get_input(YesNo, "commencer une partie ? (yes/no)\n");
        

    } while (continue_play);
    

}