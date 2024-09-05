#include <stdio.h>
#define square(x) (x) * (x)
#define SECS_PER_YEAR 60*60*24*365UL


int main() {
    int a = 3;
    int b = 4;
    int a_square = square(a+b);

    printf("SECS_PER_YEAR: %d\n", SECS_PER_YEAR);

    int pa[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    int *p[10] = {0, (int*)1, (int*)2, (int*)3, (int*)4, (int*)5, (int*)6, (int*)7, (int*)8, (int*)9};
    int (*pp)[10] = &pa;

    return 0;
}