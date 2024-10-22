#include <stdlib.h>

struct qq {
    int a;
    float b;
    long c;
    char d;
};

int main() {
    struct qq *obj = (struct qq*)malloc(sizeof(struct qq));
    obj->a = 1;
    obj->b = 2;
    obj->c = 3;
    obj->d = 4;

    return 0;
}