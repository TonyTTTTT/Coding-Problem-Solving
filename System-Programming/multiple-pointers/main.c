typedef void(*pf)(char *);

int main() {
    void(*(*papf)[3])(char *);
    pf(*new_papf)[3];

    return 0;
}