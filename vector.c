#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include "vector.h"

p_s_vector vector_alloc(size_t n, t_data_alloc f_alloc, t_data_free f_free, t_data_cpy f_cpy)
{
    p_s_vector vector = malloc(sizeof(s_vector));
    if (vector == NULL) return NULL;
    vector->function_malloc = f_alloc;
    vector->function_free = f_free;
    vector->function_copy = f_cpy;
    vector->elements = vector->function_malloc(n);
    vector->capacity = n * n;
    vector->size = n;
    return vector;
}

void vector_free(p_s_vector p_vector)
{
    p_vector->function_free(p_vector->elements);
    free(p_vector);
}

void vector_set(p_s_vector p_vector, size_t i, void* v)
{
    if (0 > i || i > p_vector->size) return; // Si le i n'est pas dans le tableau
    p_vector->function_copy(p_vector->elements[i], v);
}

void* get(p_s_vector p_vector, size_t i)
{
    return (0 > i || i > p_vector->size)? NULL : p_vector->elements[i];
}

void vector_get(p_s_vector p_vector, size_t i, void * p_data)
{
    p_vector->function_copy(p_data, p_vector->elements[i]);
}

void vector_insert(p_s_vector p_vector, size_t i, void* v)
{
    if (0 > i || i > p_vector->size) return; // Si le i n'est pas dans le tableau
    p_vector->size += 1;
    if (p_vector->size == p_vector->capacity)
        _realloc_according_capacity(p_vector, p_vector->capacity * 2);
    int replaced = 0;
    void* element_saved = NULL;
    void* element_selected = NULL;
    for (size_t j = 0; j < p_vector->size; j++) {
        p_vector->function_copy(element_selected, element_saved);
        p_vector->function_copy(element_saved, p_vector->elements[j]);
        if (i == j) replaced = 1;
        else if (replaced) p_vector->function_copy(p_vector->elements[j], element_saved);
    }
    p_vector->function_copy(p_vector->elements[i], v);
}

void vector_erase(p_s_vector p_vector, size_t i)
{
    if (0 > i || i > p_vector->size) return; // Si le i n'est pas dans le tableau
    p_vector->size -= 1;
    int replaced = 0;
    for (size_t j = 0; j < p_vector->size + 1; j++) {
        if (i == j) replaced = 1;
        else if (replaced) p_vector->function_copy(p_vector->elements[j - replaced], p_vector->elements[j]);
    }
    if (p_vector->size <= p_vector->capacity / 4)
        _realloc_according_capacity(p_vector, p_vector->capacity / 2);
}

void _realloc_according_capacity(p_s_vector p_vector, size_t new_capacity)
{
    size_t vector_size = p_vector->size;
    p_vector->capacity = new_capacity;
    void** new_elements = p_vector->function_malloc(p_vector->capacity);
    if (new_elements == NULL) exit(EXIT_FAILURE);
    for (size_t j = 0; j < vector_size; j++)
        p_vector->function_copy(new_elements[j], p_vector->elements[j]);
    vector_clear(p_vector);
    p_vector->elements = new_elements;
    p_vector->size = vector_size;
}

void vector_push_back(p_s_vector p_vector, void* v)
{
    vector_insert(p_vector, p_vector->size, v);
}

void vector_pop_back(p_s_vector p_vector)
{
    vector_erase(p_vector, p_vector->size - 1);
}

void vector_clear(p_s_vector p_vector)
{
    p_vector->function_free(p_vector);
    p_vector->size = 0;
}

int vector_empty(p_s_vector p_vector)
{
    return (!p_vector->size)? 1 : 0;
}

size_t vector_size(p_s_vector p_vector)
{
    return p_vector->size;
}
