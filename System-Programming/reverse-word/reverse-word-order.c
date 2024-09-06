#include <string.h>
#include <stdlib.h>

char * reverse(char *s);
void substr(char *dest, char *src, int len);

int main() {
    char s[] = "Fuck that ASS and dog and bee and what ever thedfaseli is for eee!";

    char *s_rev = reverse(s);

    return 0;
}

char * reverse(char *s) {
    char *r, *l;
    r = s;

    while (*(r+1)) r++;

    l = r;
    char *s_rev = (char*)malloc(1024);
    memset(s_rev, 0, sizeof(s_rev));
    char *word = (char*)malloc(20);
    memset(word, 0, sizeof(word));
    char *tmp = l;

    while (tmp != s-1) {
        while (*l != ' ' && l != s-1) l--;
        tmp = l == s-1 ? l : l-1;
        substr(word, l+1, r-l);
        strcat(s_rev, word);
        strcat(s_rev, " ");
        r = l = tmp;
    }
    *(s_rev+strlen(s_rev)-1) = 0;

    return s_rev;
}

void substr(char *dest, char *src, int len) {
    strncpy(dest, src, len);
    *(dest+len) = 0;
}