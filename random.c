#include "random.h"
#include <stdlib.h>

#ifndef __RANDOM__
#define __RANDOM__

// ((double)rand()) / (RAND_MAX + 1) => [0,1[

double random_double(double a, double b)
{
	return ((double)rand() * (b - a)) / (double)RAND_MAX + a;
}

float random_float(float a, float b)
{
	return ((float)rand() * (b - a)) / (float)RAND_MAX + a;
}

size_t random_size_t(size_t a, size_t b)
{
	return ((size_t)rand() * (b - a) / (size_t)RAND_MAX + a);
}

int random_int(int a, int b)
{
	return (rand() * (b - a)) / RAND_MAX + a;	
}

unsigned char random_uchar(unsigned char a, unsigned char b)
{
	return ((unsigned char)rand() * (b - a) / (unsigned char)RAND_MAX + a);
}

void random_init_string(unsigned char * c, size_t n)
{
	for (size_t i = 0; i < n; i++) {
		int rng = random_uchar('A', 'Z');
		c[i] = rng;
	}
	c[n] = '\0';
}

#endif
