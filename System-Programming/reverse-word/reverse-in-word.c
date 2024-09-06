void reverse_word(char* s);
void swap(char *a, char *b);

int main() {
    char s[] = "He is a boy";

    reverse_word(s);

    return 0;
}

void reverse_word(char *s) {
    char *l, *r;
    l = r = s;

    while (*s != '\0') {
        while (*r != ' ' && *r != '\0') r++;
        s = *r == '\0' ? r : r+1;

        r--;
        while (l < r) {
            swap(l, r);
            l++;r--;
        }
        l = r = s;
    }
}

void swap(char *a, char *b) {
    char tmp = *a;
    *a = *b;
    *b = tmp;
}