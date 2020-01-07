#include "vector_v1_double.h"
#include "random.h"
#include <stdio.h>
#include <stddef.h>
#include <string.h>

/**
 * Echange la position de la valeur situe a la ieme
 * valeur du vecteur par la ieme + 1.
 * Utilisé par le bubble sort.
 * @param p_vector Le vector ou l'on fait l'operation.
 * @param i        L'index.
 */
void _swap(p_s_vector_v1_double p_vector, size_t i)
{
    double index_value = get(p_vector, i);
    vector_v1_double_set(p_vector, i, get(p_vector, i + 1));
    vector_v1_double_set(p_vector, i + 1, index_value);
}

/**
 * Bubble sort recursif sur un vecteur.
 * @param p_vector  Le vecteur a trier.
 * @param list_size La longueur restante a trier.
 */
void _sort(p_s_vector_v1_double p_vector, size_t list_size)
{
    if (list_size == 1) return;
    for (int i = 0; i < list_size - 1; i++) {
        if (get(p_vector, i) > get(p_vector, i + 1))
            _swap(p_vector, i);
    }
    _sort(p_vector, list_size - 1);
}

void insert_erase_random(p_s_vector_v1_double p_vector, size_t n)
{
    for (size_t i = 0; i < n; ++i)
    {
        size_t rng = random_size_t(0, p_vector->size);
        vector_v1_double_insert(p_vector, rng, -1);
    }
    for (size_t i = 0; i < n; ++i)
    {
        size_t rng = random_size_t(0, p_vector->size);
        vector_v1_double_erase(p_vector, rng);
    }
}

void insert_erase_head(p_s_vector_v1_double p_vector, size_t n)
{
    for (size_t i = 0; i < n; ++i)
        vector_v1_double_insert(p_vector, 0, -1);
    for (size_t i = 0; i < n; ++i)
        vector_v1_double_erase(p_vector, 0);
}

void insert_erase_tail(p_s_vector_v1_double p_vector, size_t n)
{
    for (size_t i = 0; i < n; ++i)
        vector_v1_double_push_back(p_vector, -1);
    for (size_t i = 0; i < n; ++i)
        vector_v1_double_pop_back(p_vector);
}

void read_write_random(p_s_vector_v1_double p_vector, size_t n)
{
    for (size_t i = 0; i < n; ++i)
    {
        size_t rng = random_size_t(0, p_vector->size);
        vector_v1_double_set(p_vector, rng, -1);
    }
    for (size_t i = 0; i < n; ++i)
    {
        size_t rng = random_size_t(0, p_vector->size);
        get(p_vector, rng);
    }
}

void read_write_sequential(p_s_vector_v1_double p_vector, size_t n)
{
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < p_vector->size; ++j)
            vector_v1_double_set(p_vector, j, j);
        for (size_t j = 0; j < p_vector->size; ++j)
            get(p_vector, j);
    }
}

void bubble_sort(p_s_vector_v1_double p_vector, size_t n)
{
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < p_vector->size; ++j)
        {
            size_t rng = random_size_t(0, 100);
            vector_v1_double_set(p_vector, j, rng);
        }
        _sort(p_vector, p_vector->size);
    }
}

int main(int argc, char const *argv[])
{
    if (argc < 4)
    {
        printf("Usage: ./bench_vector_v1_double test_type init_size n\n");
        return 0;
    }
    size_t init_size, n;

    sscanf(argv[2], "%ld", &init_size);
    sscanf(argv[3], "%ld", &n);

    printf("\nStart bench\ntest: %s\ninit_size: %d\nn: %d\n", argv[1], init_size, n);

    p_s_vector_v1_double vector = vector_v1_double_alloc(init_size);
    for (int i = 0; i < init_size; ++i)
        vector_v1_double_set(vector, i, random_double(0, 100));
    if (0 == strcmp(argv[1], "insert_erase_random"))
        insert_erase_random(vector, n);
    else if (0 == strcmp(argv[1], "insert_erase_head"))
        insert_erase_head(vector, n);
    else if (0 == strcmp(argv[1], "insert_erase_tail"))
        insert_erase_tail(vector, n);
    else if (0 == strcmp(argv[1], "read_write_random"))
        read_write_random(vector, n);
    else if (0 == strcmp(argv[1], "read_write_sequential"))
        read_write_sequential(vector, n);
    else if (0 == strcmp(argv[1], "bubble_sort"))
        bubble_sort(vector, n);
    else
        printf("Test unknown\n");
    
    vector_v1_double_free(vector);

    return 0;
}
