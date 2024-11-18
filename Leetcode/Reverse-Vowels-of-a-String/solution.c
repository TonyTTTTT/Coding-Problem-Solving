#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char vowels[] = "aeiouAEIOU";
bool isVowel(char c) {
    for (int i=0; i<10; i++) {
        if (c == vowels[i]) return true;
    }
    return false;
}

char* reverseVowels(char* s) {
    int l = 0, r = strlen(s) - 1;

    while (l < r) {
        while (l<r && !isVowel(s[l])) l++;
        while (l<r && !isVowel(s[r])) r--;
        if (l < r) {
            char tmp;
            tmp = *(s+l);
           *(s+l) = *(s+r);
           *(s+r) = tmp;
        }
        l++;
        r--;
    }

    return s;
}

int main() {
    char s[] = "IceCreAm";

    char *ans = reverseVowels(s);

    return 0;
}