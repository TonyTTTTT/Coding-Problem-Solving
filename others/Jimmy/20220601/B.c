#include<stdio.h>
#include<string.h>

void turn(int* ,char[]);

int main()
{
    int n ,count;
    scanf("%d",&n);

    while( n != 0) {
        int dice[6] = {1 , 5, 2, 4, 6, 3};
        char position[n][6];
        for(count = 0;count < n;count++) {
            scanf("%s", position[count]);//寫入指令順序
            // printf("%s\n", position[count]);
        }
        for(count = 0;count < n;count++) {
            turn(&dice[0], position[count]);//轉動骰子
        }
        printf("%d\n",dice[0]);
        scanf("%d",&n);
    }
    return 0;
}

void turn(int* num, char a[])
{
    int temp;
    // printf("%sE\n", a);
    if (strcmp(a, "north") == 0) {
        temp = *num;
        *num = *(num + 1);
        *(num + 1) = *(num + 4);
        *(num + 4) = *(num + 2);
        *(num + 2) = temp;
    } else if (strcmp(a, "south") == 0) {
        temp = *num;
        *num = *(num + 2);
        *(num + 2) = *(num + 4);
        *(num + 4) = *(num + 1);
        *(num + 1) = temp; 
    } else if (strcmp(a, "east") == 0) {
        temp = *(num + 5);
        *(num + 5) = *(num + 4);
        *(num + 4) = *(num + 3);
        *(num + 3) = *(num + 1);
        *(num + 1) = temp;
    } else if (strcmp(a, "west") == 0) {
        temp = *(num + 1);
        *(num + 1) = *(num + 3);
        *(num + 3) = *(num + 4);
        *(num + 4) = *(num + 5);
        *(num + 5) = temp;
    } else {
        printf("wrong input\n");
    }
    return ;
}