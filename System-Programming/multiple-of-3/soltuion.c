#include <stdbool.h>

bool is_multiple_of_3(int x) {
    if (x == 0 || x == 3) return true;
    else if (x < 3) return false;

    int tmp = (x >> 2) + (x & 0b11);
    
    return is_multiple_of_3(tmp);
}

int main() {
    int x = 57;

    bool ans = is_multiple_of_3(x);

    return 0;
}