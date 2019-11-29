all : bench_vector_v1_double

bench_vector_v1_double : bench_vector_v1_double.o vector_v1_double.o random.o
	gcc bench_vector_v1_double.o vector_v1_double.o random.o -g -o bench_vector_v1_double

# test_random : test_random.o random.o
# 	gcc test_random.o random.o -g -o test_random

bench_vector_v1_double.o : bench_vector_v1_double.c
	gcc bench_vector_v1_double.c -c -g -o bench_vector_v1_double.o

vector_v1_double.o : vector_v1_double.c vector_v1_double.h
	gcc vector_v1_double.c -c -g -o vector_v1_double.o

random.o : random.c random.h
	gcc random.c -c -g -o random.o

test_random.o : test_random.c
	gcc test_random.c -c -g -o test_random.o

clean :
	rm -f *.o test_random
