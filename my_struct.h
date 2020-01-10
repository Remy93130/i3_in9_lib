#include <stddef.h>

#ifndef __MY_STRUCT_H__
#define __MY_STRUCT_H__

struct struct_my_struct
{
    char* string;
    double number;
};

typedef struct struct_my_struct s_my_struct;
typedef s_my_struct * p_s_my_struct;

p_s_my_struct my_struct_alloc();

void my_struct_free(p_s_my_struct p_vector);

void my_struct_randoms_init(p_s_my_struct p_vector);

void my_struct_copy(p_s_my_struct p_dest, p_s_my_struct p_src);

/**
 * 0 si identique
 * 1 si p_vector_a est apres p_vector_b
 * -1 si p_vector_a est avant p_vector_b
 * @param  p_vector_a [description]
 * @param  p_vector_b [description]
 * @return            [description]
 */
int my_struct_cmp(p_s_my_struct p_vector_a, p_s_my_struct p_vector_b);

#endif
