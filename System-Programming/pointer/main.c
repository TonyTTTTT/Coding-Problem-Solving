void change(int *a) {
    *a = 5;
}

int main() {
    int b = 6;

    change(&b);

    int a[10] = {1,2,3,4,5,6,7,8,9,10};

    int *p = &(a+1)[3];

    return 0;
}