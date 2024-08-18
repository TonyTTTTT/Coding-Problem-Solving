#include <stdio.h>
#include "main.h"

int test() {
    return puts("Hello World");
}

void wrapper(int (*func)()) {
    func();
}

int main() {
    int res = test();

    int res2 = puts("Hello World");

    printf("res: %d\nres2: %d\n", res, res2);

    int (*fptr)(int, int) = &add;

    wrapper(test);

    return 0;
}

int add(int a, int b) {
    return a+b;
}