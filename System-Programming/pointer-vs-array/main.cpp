#include <iostream>

void array_vs_pointer() {
    int a[5] = {1,2,3,4,5};
    int *p = (int*)(&a+1);

    printf("%d, %d\n", *(a+1), *(p-1));
}

#include <stdio.h>

void print_str(void) {
	char *str[] = {
	    {"MediaTekOnlineTesting"},
	    {"WelcomeToHere"},
	    {"Hello"},
	    {"EverydayGenius"},
	    {"HopeEverythingGood"}
	};
	char* m = str[4] + 4;
	char* n = str[1];
	char* p = *(str+2) + 4;
	printf("1. %s\n", *(str+1));
	printf("2. %s\n", (str[3]+8));
	printf("3. %c\n", *m);
	printf("4. %c\n", *(n+3));
	printf("5. %c\n", *p + 1);
	// 1. WelcomeToHere
	// 2. Genius
	// 3. E
	// 4. c
	// 5. p
    return;
}

int main() {
    char *p = "test";
    char a[] = "test";

    a[0] = 'g';
    // p[0] = 's';

    array_vs_pointer();

    print_str();

    return 0;
}