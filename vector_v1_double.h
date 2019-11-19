#include <stddef.h>

#ifndef __VECTOR_V1_DOUBLE_H__
#define __VECTOR_V1_DOUBLE_H__

struct struct_vector_v1_double
{
	size_t size;
	double* elements;
};

typedef struct struct_vector_v1_double s_vector_v1_double;
typedef s_vector_v1_double * p_s_vector_v1_double;

p_s_vector_v1_double vector_v1_double_alloc(size_t n);

void vector_v1_double_free(p_s_vector_v1_double p_vector);

void vector_v1_double_set(p_s_vector_v1_double p_vector, size_t i, double v);

double get(p_s_vector_v1_double p_vector, size_t i);

void vector_v1_double_insert(p_s_vector_v1_double p_vector, size_t i, double v);

void vector_v1_double_erase(p_s_vector_v1_double p_vector, size_t i);

void vector_v1_double_push_back(p_s_vector_v1_double p_vector,double v);

void vector_v1_double_pop_back(p_s_vector_v1_double p_vector);

int vector_v1_double_empty(p_s_vector_v1_double p_vector);

size_t vector_v1_double_size(p_s_vector_v1_double p_vector);

#endif