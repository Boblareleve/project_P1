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
