#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include "my_struct.h"
#include "random.h"

p_s_my_struct my_struct_alloc()
{
    p_s_my_struct strc = malloc(sizeof(s_my_struct));
    if (strc == NULL) return NULL;
    strc->string = NULL;
    strc->number = 0.0;
    return strc;
}

void my_struct_free(p_s_my_struct p_vector)
{
    free(p_vector->string);
    free(p_vector);
}

void my_struct_randoms_init(p_s_my_struct p_vector)
{
    p_vector->number = random_double(0.0, 5000.0);
    size_t size = random_size_t(0, 20);
    p_vector->string = malloc(sizeof(char) * size);
    random_init_string(p_vector->string, size);
}

void my_struct_copy(p_s_my_struct p_dest, p_s_my_struct p_src)
{
    if (p_dest == NULL || p_src == NULL) return;
    p_dest->string = malloc(sizeof(char) * strlen(p_src->string));
    strcpy(p_dest->string, p_src->string);
    p_dest->number = p_src->number;
}