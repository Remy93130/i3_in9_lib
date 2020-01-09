all : test_vector_v1_double test_random bench_vector_v1_double test_vector_v2_double test_my_struct

# Vector V1

test_vector_v1_double : test_vector_v1_double.o vector_v1_double.o
	gcc vector_v1_double.o test_vector_v1_double.o -g -o test_vector_v1_double

bench_vector_v1_double : bench_vector_v1_double.o vector_v1_double.o random.o
	gcc bench_vector_v1_double.o vector_v1_double.o random.o -g -o bench_vector_v1_double

vector_v1_double.o : vector_v1_double.c vector_v1_double.h
	gcc vector_v1_double.c -c -g -o vector_v1_double.o

test_vector_v1_double.o : test_vector_v1_double.c
	gcc test_vector_v1_double.c -c -g -o test_vector_v1_double.o

bench_vector_v1_double.o : bench_vector_v1_double.c
	gcc bench_vector_v1_double.c -c -g -o bench_vector_v1_double.o

# Vector V2

test_vector_v2_double : test_vector_v2_double.o vector_v2_double.o
	gcc vector_v2_double.o test_vector_v2_double.o -g -o test_vector_v2_double

bench_vector_v2_double : bench_vector_v2_double.o vector_v2_double.o random.o
	gcc bench_vector_v2_double.o vector_v2_double.o random.o -g -o bench_vector_v2_double

test_vector_v2_double.o : test_vector_v2_double.c
	gcc test_vector_v2_double.c -c -g -o test_vector_v2_double.o

vector_v2_double.o : vector_v2_double.c vector_v2_double.h
	gcc vector_v2_double.c -c -g -o vector_v2_double.o

bench_vector_v2_double.o : bench_vector_v2_double.c
	gcc bench_vector_v2_double.c -c -g -o bench_vector_v2_double.o

# Random

test_random : test_random.o random.o
	gcc test_random.o random.o -g -o test_random

random.o : random.c random.h
	gcc random.c -c -g -o random.o

test_random.o : test_random.c
	gcc test_random.c -c -g -o test_random.o

# My Struct

test_my_struct : test_my_struct.o my_struct.o random.o
	gcc test_my_struct.o my_struct.o random.o -g -o test_my_struct

my_struct.o : my_struct.c my_struct.h
	gcc my_struct.c -c -g -o my_struct.o

test_my_struct.o : test_my_struct.c
	gcc test_my_struct.c -c -g -o test_my_struct.o

clean :
	rm -f *.o \
		test_vector_v1_double \
		test_random bench_vector_v1_double \
		test_vector_v2_double bench_vector_v2_double \
		test_my_struct
