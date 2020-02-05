#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "random.h"

#define STRING_SIZE 10

int main(int argc, char const *argv[])
{
    printf("Random double (-1, 1)\n\t%f\n", random_double(-1, 1));
    printf("Random float (0, 10)\n\t%f\n", random_float(0, 10));
    printf("Random size_t (0, 10)\n\t%ld\n", random_size_t(0, 10));
    printf("Random int (0, 100)\n\t%d\n", random_int(0, 100));
    printf("Random uchar (0, 100)\n\t%d\n", random_uchar(0, 100));

    char string[STRING_SIZE];
    if (string == NULL) return 1;
    random_init_string(string, STRING_SIZE);
    printf("Random string len = %d\n\t%s\n", STRING_SIZE, string);
    return 0;
}
