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

int main(int argc, char (*argv)[0]) {
    puts(((char **) argv)[0]);
    return 0;
}