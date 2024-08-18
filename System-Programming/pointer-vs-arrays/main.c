#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// int main() {
//     int a[3];
//     struct {
//         double v[3];
//         double length;
//     } b[17];
//     int calendar[12][31];

//     char* s = "abc";
//     char* t = "klmn";

//     char* r = (char*)malloc(sizeof(char));
//     if (!r) exit(1);
//     strcpy(r, s);
//     strcat(r, t);
    
//     free(r);
//     r = NULL;

//     return 0;
// }

int main(int argc, char (**argv)[0]) {
    puts(((char **) argv)[0]);

    int (*a)[10];
    int b[10] = {0,1,2,3,4,5,6,7,8,9};
    int c[10] = {0,41,52,33,4,55,86,97,84,9};

    memcpy(a, b, sizeof(b));
    // *(a+1) = c;

    return 0;
}

