#include "input.h"

//fonction qui permet de recuperer les inputs
int getInput(input_t type_dinput, char *msg)
{
    

    bool valide_input;
    char input[100];

    switch (type_dinput) //définition du switch oui/non pour apres pouvir l'utiliser dans les fonctions tels que le lancé de dée
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

        } while ((strcmp(input, "oui") != 0) && (strcmp(input, "non") != 0));//les inputs sont obligatoirement en français(oui/non)

        return (input[0] == 'o');

    case integer:
        printf("%s", msg);
        scanf("%99s", input);
        if (input[0] == 'q')
        {
            printf("quitte le jeu\n");
            exit(0);
        }
        return (atoi(input));

    case area:

        printf("%s", msg);
        scanf("\n");
        scanf("%c", input);
        //printf("%c", input[0]);
        while (input[0] != house
            && input[0] != finish
            && input[0] != mainBoard
            )
        {
            printf("zone invalid\n");
            scanf("%c", input);
        }
        return ((int)input[0]);


    default:
        return -1;
    }
    
} 
