#include <stddef.h>

#ifndef __VECTOR_V1_DOUBLE_H__
#define __VECTOR_V1_DOUBLE_H__

typedef struct struct_vector_v1_double
{
	size_t size;
	double* elements;
} ps_vector_v1_double;

ps_vector_v1_double vector_v1_double_alloc(size_t n);

void vector_v1_double_set(ps_vector_v1_double p_vector, size_t i, double v);

double get(ps_vector_v1_double p_vector, size_t i);

void vector_v1_double_insert(ps_vector_v1_double p_vector, size_t i, double v);

void vector_v1_double_erase(ps_vector_v1_double p_vector, size_t i);

void vector_v1_double_push_back(ps_vector_v1_double p_vector,double v);

void vector_v1_double_pop_back(ps_vector_v1_double p_vector);

int vector_v1_double_empty(ps_vector_v1_double p_vector);

size_t vector_v1_double_size(ps_vector_v1_double p_vector);

#endif