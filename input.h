

#ifndef __INPUT_H__
#define __INPUT_H__


#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef enum 
{
    YesNo,

} input_t;


int get_input(input_t, char* msg);


#endif