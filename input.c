#include "input.h"




int getInput(input_t type_dinput, char *msg)
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
