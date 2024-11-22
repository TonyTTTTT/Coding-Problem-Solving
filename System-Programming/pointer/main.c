static void change(int *a, const int b) {
    *a = 5;
}

int main() {
    int b = 6;

    change(&b, 8);

    int a[10] = {1,2,3,4,5,6,7,8,9,10};

    int *p = &(a+1)[3];

    return 0;
}