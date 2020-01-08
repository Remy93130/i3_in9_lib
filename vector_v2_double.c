#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include "vector_v2_double.h"

void _affiche_vector(p_s_vector_v2_double vector)
{
    printf("[");
    for (int i = 0; i < vector->size; i++) {
        if (i != 0) printf(", ");
        printf("%.1f", get(vector, i));
    }
    printf("]\n");
}

p_s_vector_v2_double vector_v2_double_alloc(size_t n)
{
    p_s_vector_v2_double vector = malloc(sizeof(s_vector_v2_double));
    if (vector == NULL) return NULL;
    vector->elements = malloc(sizeof(double) * n * n);
    vector->capacity = n * n;
    for (size_t i = 0; i < n; i++) vector->elements[i] = 0.0;
    vector->size = n;
    return vector;
}

void vector_v2_double_free(p_s_vector_v2_double p_vector)
{
    free(p_vector->elements);
    free(p_vector);
}

void vector_v2_double_set(p_s_vector_v2_double p_vector, size_t i, double v)
{
    if (0 > i || i > p_vector->size) return; // Si le i n'est pas dans le tableau
    p_vector->elements[i] = v;
}

double get(p_s_vector_v2_double p_vector, size_t i)
{
    return (0 > i || i > p_vector->size)? -1.0 : p_vector->elements[i];
}

void vector_v2_double_insert(p_s_vector_v2_double p_vector, size_t i, double v)
{
    if (0 > i || i > p_vector->size) return; // Si le i n'est pas dans le tableau
    p_vector->size += 1;
    if (p_vector->size == p_vector->capacity)
        _realloc_according_capacity(p_vector, p_vector->capacity * 2);
    int replaced = 0;
    double element_saved = -1;
    double element_selected;
    for (size_t j = 0; j < p_vector->size - 1; j++) {
        element_selected = element_saved;
        element_saved = p_vector->elements[j];
        if (i == j) replaced = 1;
        else if (replaced) p_vector->elements[j] = element_selected;
    }
    p_vector->elements[i] = v;
}

void vector_v2_double_erase(p_s_vector_v2_double p_vector, size_t i)
{
    if (0 > i || i > p_vector->size) return; // Si le i n'est pas dans le tableau
    p_vector->size -= 1;
    vector_v2_double_clear(p_vector);
    printf("freed\n");
    int replaced = 0;
    for (size_t j = 0; j < p_vector->size; j++) {
        if (i == j) replaced = 1;
        else if (replaced) p_vector->elements[j - replaced] = p_vector->elements[j];
    }
    if (p_vector->size <= p_vector->capacity / 4)
        _realloc_according_capacity(p_vector, p_vector->capacity / 2);
}

void _realloc_according_capacity(p_s_vector_v2_double p_vector, size_t new_capacity)
{
    printf("called with capacity %ld\n", new_capacity);
    size_t vector_size = p_vector->size;
    p_vector->capacity = new_capacity;
    double* new_elements = malloc(sizeof(double) * p_vector->capacity);
    if (new_elements == NULL) printf("KO\n");
    printf("malloc ok\n");
    for (int j = 0; j < vector_size; j++)
        new_elements[j] = p_vector->elements[j];
    // vector_v2_double_clear(p_vector);
    p_vector->elements = new_elements;
    p_vector->size = vector_size;
}

void vector_v2_double_push_back(p_s_vector_v2_double p_vector, double v)
{
    vector_v2_double_insert(p_vector, p_vector->size, v);
}

void vector_v2_double_pop_back(p_s_vector_v2_double p_vector)
{
    vector_v2_double_erase(p_vector, p_vector->size - 1);
}

void vector_v2_double_clear(p_s_vector_v2_double p_vector)
{
    free(p_vector->elements);
    p_vector->size = 0;
}

int vector_v2_double_empty(p_s_vector_v2_double p_vector)
{
    return (!p_vector->size)? 1 : 0;
}

size_t vector_v2_double_size(p_s_vector_v2_double p_vector)
{
    return p_vector->size;
}
