#include<stdio.h>

long long reverse(long long);

int main()
{
    int N;
    long long num;
    scanf("%d",&N);
    for(int i = 1;i <= N;i++) {
        scanf("%u",&num);
        int count = 1;
        num += reverse(num);
        while(reverse(num) != num) {
            num += reverse(num);
            count++;
        }
        printf("%d %lld\n", count, num);
    }
    return 0;
}

long long reverse(long long a)
{
    long long b = 0;
    while(a != 0) {
        b = b * 10 + a % 10;
        a /= 10;
    }
    return b;
}