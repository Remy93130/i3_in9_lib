all : test_vector_v1_double

test_vector_v1_double : test_vector_v1_double.o vector_v1_double.o
	gcc vector_v1_double.o test_vector_v1_double.o -g -o test_vector_v1_double

vector_v1_double.o : vector_v1_double.c vector_v1_double.h
	gcc vector_v1_double.c -c -g -o vector_v1_double.o

test_vector_v1_double.o : test_vector_v1_double.c
	gcc test_vector_v1_double.c -c -g -o test_vector_v1_double.o

clean :
	rm -f *.o test_vector_v1_double
