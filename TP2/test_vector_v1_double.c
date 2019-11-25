#include "vector_v1_double.h"
#include <stdio.h>

void affiche_vector(p_s_vector_v1_double vector)
{
	printf("[");
	for (int i = 0; i < vector->size; i++) {
		if (i != 0) printf(", ");
		printf("%.1f", get(vector, i));
	}
	printf("]\n");
}

int main(int argc, char *argv[])
{
	// Test alloc
	printf("Test vector_v1_double_alloc(5) :\n\tExpexted : [0.0, 0.0, 0.0, 0.0, 0.0]\n\tGot\t : ");
	p_s_vector_v1_double vector = vector_v1_double_alloc(5);
	affiche_vector(vector);
	
	// Test set
	printf("Test vector_v1_double_set :\n\tExpected : [5.0, 4.0, 3.0, 2.0, 1.0]\n\tGot\t : ");
	vector_v1_double_set(vector, 0, 5.0);
	vector_v1_double_set(vector, 1, 4.0);
	vector_v1_double_set(vector, 2, 3.0);
	vector_v1_double_set(vector, 3, 2.0);
	vector_v1_double_set(vector, 4, 1.0);
	affiche_vector(vector);
	
	// Test insert
	printf("Test vector_v1_double_insert :\n\tExpected : [12.0, 5.0, 4.0, 3.0, 0.0, 2.0, 1.0]\n\tGot\t : ");
	vector_v1_double_insert(vector, 0, 12.0);
	vector_v1_double_insert(vector, 4, 0.0);
	affiche_vector(vector);
	
	// Test erase
	printf("Test vector_v1_double_erase :\n\tExpected : [5.0, 4.0, 4.0, 2.0, 1.0]\n\tGot\t : ");
	vector_v1_double_erase(vector, 0);
	vector_v1_double_erase(vector, 3);
	affiche_vector(vector);

	// Test push
	printf("Test vector_v1_double_push_back :\n\tExpected : [5.0, 4.0, 4.0, 2.0, 1.0, 42.0]\n\tGot\t : ");
	vector_v1_double_push_back(vector, 42.0);
	affiche_vector(vector);

	// Test pop
	printf("Test vector_v1_double_pop_back :\n\tExpected : [5.0, 4.0, 4.0, 2.0, 1.0]\n\tGot\t : ");
	vector_v1_double_pop_back(vector);
	affiche_vector(vector);

	// Test empty
	printf("Test vector_v1_double_empty :\n\tExpected : 0\n\tGot\t : %d\n", vector_v1_double_empty(vector));

	// Test size
	printf("Test vector_v1_double_empty :\n\tExpected : 5\n\tGot\t : %ld\n", vector_v1_double_size(vector));

	vector_v1_double_free(vector);
}
