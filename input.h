

#ifndef __INPUT_H__
#define __INPUT_H__


#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef enum 
{
    YesNo,
    integer,

} input_t;


int getInput(input_t, char* msg);


#endif