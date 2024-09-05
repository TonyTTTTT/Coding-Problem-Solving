#include <stdio.h>
#include "main.h"

int test() {
    return puts("Hello World");
}

int wrapper(int (*func)(int, int), int a, int b) {
    return func(a, b);
}

int main() {
    int res = test();

    int res2 = puts("Hello World");

    printf("res: %d\nres2: %d\n", res, res2);

    int (*fptr)(int, int) = &add;

    printf("additoin result: %d\n", wrapper(fptr, 3, 6));

    return 0;
}

int add(int a, int b) {
    return a+b;
}