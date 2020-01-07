#include "vector_v1_double.h"
#include "random.h"
#include <stdio.h>
#include <stddef.h>
#include <string.h>

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
        /* code */
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
}
