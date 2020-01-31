#include "vector.h"
#include "random.h"
#include <stdio.h>

#define MIN_ADDRESS 0
#define MAX_ADDRESS 5000000

void affiche_vector(p_s_vector vector)
{
    printf("[");
    for (int i = 0; i < vector->size; i++) {
        if (i != 0) printf(", ");
        printf("%p", get(vector, i));
    }
    printf("]\n");
}

int main(int argc, char *argv[])
{
	init_seed();
    // Test alloc
    printf("Test vector_alloc(5) :\n\tExpexted : [0.0, 0.0, 0.0, 0.0, 0.0]\n\tGot\t : ");
    p_s_vector vector = vector_alloc(5, NULL, &vector_free, NULL);
    affiche_vector(vector);
    
    // Test set
    printf("Test vector_set :\n\tExpected : [5.0, 4.0, 3.0, 2.0, 1.0]\n\tGot\t : ");
    vector_set(vector, 0, (void*)random_size_t(MIN_ADDRESS, MAX_ADDRESS));
    vector_set(vector, 1, (void*)random_size_t(MIN_ADDRESS, MAX_ADDRESS));
    vector_set(vector, 2, (void*)random_size_t(MIN_ADDRESS, MAX_ADDRESS));
    vector_set(vector, 3, (void*)random_size_t(MIN_ADDRESS, MAX_ADDRESS));
    vector_set(vector, 4, (void*)random_size_t(MIN_ADDRESS, MAX_ADDRESS));
    affiche_vector(vector);

    
    // Test insert
    printf("Test vector_insert :\n\tExpected : [12.0, 5.0, 4.0, 3.0, 0.0, 2.0, 1.0]\n\tGot\t : ");
    vector_insert(vector, 0, (void*)random_size_t(MIN_ADDRESS, MAX_ADDRESS));
    vector_insert(vector, 4, (void*)random_size_t(MIN_ADDRESS, MAX_ADDRESS));
    affiche_vector(vector);
    
    // Test erase
    printf("Test vector_erase :\n\tExpected : [5.0, 4.0, 3.0, 2.0, 1.0]\n\tGot\t : ");
    vector_erase(vector, 0);
    vector_erase(vector, 3);
    affiche_vector(vector);

    // Test push
    printf("Test vector_push_back :\n\tExpected : [5.0, 4.0, 3.0, 2.0, 1.0, 42.0]\n\tGot\t : ");
    vector_push_back(vector, (void*)random_size_t(MIN_ADDRESS, MAX_ADDRESS));
    affiche_vector(vector);

    // Test pop
    printf("Test vector_pop_back :\n\tExpected : [5.0, 4.0, 3.0, 2.0, 1.0]\n\tGot\t : ");
    vector_pop_back(vector);
    affiche_vector(vector);

    // Test empty
    printf("Test vector_empty :\n\tExpected : 0\n\tGot\t : %d\n", vector_empty(vector));

    // Test size
    printf("Test vector_empty :\n\tExpected : 5\n\tGot\t : %d\n", vector_size(vector));

    vector_free(vector);
}
