#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "my_struct.h"
#include "random.h"

#define STRING_SIZE 10

void affiche_struct(p_s_my_struct p_vector)
{
	printf("[%f, \"%s\"]\n", p_vector->number, p_vector->string);
}

int main(int argc, char const *argv[])
{
	init_seed();
	// Create struct
	p_s_my_struct my_struct = my_struct_alloc();
	my_struct_randoms_init(my_struct);
	printf("Struct created: ");
	affiche_struct(my_struct);
}
