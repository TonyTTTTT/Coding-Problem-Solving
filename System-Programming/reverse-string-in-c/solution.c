void swap(char* a, char* b) {
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

char* reverse(char* s) {
    int r = 0;
    while (*(s+r+1) != '\0') r++;
    int l = 0;
    
    while (l < r) {
        swap(s+l, s+r);
        l++;r--;
    }

    return s;
}

bool is2Pow(int n) {
    int a = ~n;
    int b = !n;
    return !(n & (n-1)) && n != 0;
}

int main() {
    char s[] = "abcde";

    char* s_rev = reverse(s);

    bool ans = is2Pow(19);

    return 0;
}