#include <stdio.h>

void change(int &b) {
    b = 3;
}

int var;

int bar(int var) {
    var += 1;
    return var * var;
}

int foo() {
    var += bar(++var);
}

int main() {
    int a =10, b=20;
    int c = a = b;

    int i;double d;
    // d = i = 3.5;
    i = d = 3.5;

    int x = 2;
    change(x);

    printf("%d\n", foo());

    return 0;
}