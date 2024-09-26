void change(int *a) {
    *a = 5;
}

int main() {
    int b = 6;

    change(&b);

    return 0;
}