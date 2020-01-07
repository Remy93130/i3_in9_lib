all : test_my_struct

test_my_struct : test_my_struct.o my_struct.o
	gcc test_my_struct.o my_struct.o -g -o test_my_struct

test_my_struct.o : test_my_struct.c
	gcc test_my_struct.c -c -g -o test_my_struct.o

my_struct.o : my_struct.c
	gcc my_struct.c -c -g -o my_struct.o

clean :
	rm -f *.o test_random
