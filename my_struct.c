#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include "my_struct.h"


p_s_my_struct my_struct_alloc(){

    p_s_my_struct strc = malloc(sizeof(p_s_my_struct));
    if (strc == NULL) return NULL;
    strc->string = malloc(sizeof(char) * 1);
    return strc;

}


