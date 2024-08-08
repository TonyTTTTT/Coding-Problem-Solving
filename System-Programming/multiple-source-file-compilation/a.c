#include <stdio.h>

int x = 0;
void printXinA() {
    static int callCnt = 0;
    printf("x in a.c: %d\n", x);

    callCnt++;
    printf("printXinA been called %d time.\n", callCnt);
}