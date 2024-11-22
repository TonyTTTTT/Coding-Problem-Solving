#include <stdlib.h>

void change(int **a, int len);

int main() {
    int a[] = {0,2,4,6,8};
    int *b = a;
    change(&b, sizeof(a)/sizeof(int));

    return 0;
}

void change(int **a, int len) {
    int *new = (int*)malloc(sizeof(int) * len);

    for (int i=0; i<len; i++) {
        new[i] = (*a)[i] + 1;
    }
    *a = new;

    // for (int i=0; i<len; i++) {
    //     a[i]++;
    // }

    return;
}
