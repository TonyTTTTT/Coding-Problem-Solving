#include <stdio.h>
#include "b.h"

// extern int var;
int var = 6;

void print_var_a() {
    printf("a.c\nvar: %d\n", var);
}

int main() {
    print_var_a();
    print_var_b();
}