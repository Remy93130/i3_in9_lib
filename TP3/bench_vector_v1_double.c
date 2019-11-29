#include "vector_v1_double.h"
#include "random.h"
#include <stdio.h>
#include <stddef.h>

void insert_erase_random(p_s_vector_v1_double p_vector, size_t n)
{
	
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
	p_s_vector_v1_double vector = vector_v1_double_alloc(init_size);
	for (int i = 0; i < init_size; ++i) 
		vector_v1_double_set(vector, i, random_double(0, 100));
}