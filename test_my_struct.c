#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "my_struct.h"
#include "random.h"

#define STRING_SIZE 10

void affiche_struct(p_s_my_struct p_vector)
{
	printf("[%.2f, \"%s\"]\n", p_vector->number, p_vector->string);
}

int main(int argc, char const *argv[])
{
	init_seed();
	p_s_my_struct my_struct = my_struct_alloc();
	my_struct_randoms_init(my_struct);
	printf("Struct created: ");
	affiche_struct(my_struct);

	p_s_my_struct copied_struct = my_struct_alloc();
	my_struct_randoms_init(copied_struct);
	printf("Second struct: ");
	affiche_struct(copied_struct);

	printf("\nCompare vectors\n");
	printf("%d\n", my_struct_cmp(my_struct, copied_struct));

	my_struct_copy(copied_struct, my_struct);
	printf("\nSecond struct after copy with the first: ");
	affiche_struct(copied_struct);

	printf("\nCompare vectors\n");
	printf("%d\n", my_struct_cmp(my_struct, copied_struct));


	my_struct_free(my_struct);
	my_struct_free(copied_struct);
	return 0;
}
