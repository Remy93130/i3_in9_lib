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

#endif
