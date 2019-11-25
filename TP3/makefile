all : test_random

test_random : test_random.o random.o
	gcc test_random.o random.o -g -o test_random

random.o : random.c random.h
	gcc random.c -c -g -o random.o

test_random.o : test_random.c
	gcc test_random.c -c -g -o test_random.o

clean :
	rm -f *.o test_random
