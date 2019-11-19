vector_v1_double.o : vector_v1_double.c vector_v1_double.h
	gcc vector_v1_double.c -c -o vector_v1_double.o

clean :
	rm -f *.o program
