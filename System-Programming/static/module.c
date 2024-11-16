#include <stdio.h>

static void print_verbose(int x) {
    printf("The nums is %d\n", x);
}

int add_n_print(int a, int b) {
    int res = a + b;
    print_verbose(res);

    return res;
}