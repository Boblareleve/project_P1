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

        } while ((strcmp(input, "oui") != 0) && (strcmp(input, "non") != 0));

        return (input[0] == 'y');

    case integer:
        printf("%s", msg);
        scanf("%99s", input);
        if (input[0] == 'q')
        {
            printf("quitte le jeu\n");
            exit(0);
        }
        return (atoi(input));


    default:
        return -1;
    }
    
} 
