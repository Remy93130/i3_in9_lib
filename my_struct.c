#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include "my_struct.h"
#include "random.h"

p_s_my_struct my_struct_alloc()
{
    p_s_my_struct strc = malloc(sizeof(p_s_my_struct));
    if (strc == NULL) return NULL;
    strc->string = NULL;
    return strc;
}

void my_struct_free(p_s_my_struct p_vector)
{
    free(p_vector->string);
    free(p_vector);
}


void my_struct_randoms_init(p_s_my_struct p_vector)
{
    p_vector->number = random_double(0.0, 20.0);
    int size = random_int(0, 20);
    p_vector->string = malloc(sizeof(char)*size);
    random_init_string(p_vector->string, size);
}
