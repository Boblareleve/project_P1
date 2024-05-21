#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

typedef enum 
{
    YesNo,

} input_t;

// 
int input(input_t type_dinput, char *msg)
{
    

    bool valide_input;
    char input[100];

    switch (type_dinput)
    {
    case YesNo:
        do
        {
            printf("%s", msg);
            scanf("%99s", input);

            if (input[0] == 'q')
            {
                printf("quitte le jeu\n");
                exit(0);
            }

        } while ((strcmp(input, "yes") != 0) && (strcmp(input, "no") != 0));

        return (input[0] == 'y');

    default:
        return -1;
    }
    
} 


int main()
{


    printf("Bonjour bienvenu\n");

    bool continue_play = false; 
    char input[10];
    do
    {
        input(YesNo, "commencer une partie ? (yes/no)\n");
        

    } while (continue_play);
    

}