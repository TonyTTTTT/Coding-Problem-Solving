#include <stdlib.h>

int main() {
    int *ptr = (int*)calloc(1, sizeof(int));
    *ptr = 12345;

    int *d_ptr = (int*)0x100;
    *d_ptr = 3;

    return 0;
}