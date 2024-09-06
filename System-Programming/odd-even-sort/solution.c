#include <stdlib.h>
#include <string.h>

void * sort_custom(int *arr, int n, int *arr_sorted);
int ascend(const void *a, const void *b);
int descend(const void *a, const void *b);

int main() {
    int arr[] = {5, 9, 2, 8, 11, 78, 6, 4, 3, 99};
    int n = sizeof(arr)/sizeof(int);

    int arr_sorted[n];
    sort_custom(arr, n, arr_sorted);

    return 0;
}

void * sort_custom(int *arr, int n, int *arr_sorted) {
    int odds[n] = {0};
    int evens[n] = {0};
    int odd_cnt = 0;
    int even_cnt = 0;

    for (int i=0; i<n; i++) {
        if (arr[i] % 2 == 0) evens[even_cnt++] = arr[i];
        else odds[odd_cnt++] = arr[i];
    }

    qsort(odds, odd_cnt, sizeof(*odds), ascend);
    qsort(evens, even_cnt, sizeof(*evens), descend);

    // int *result = (int*)malloc(n*sizeof(int));
    memcpy(arr_sorted, odds, odd_cnt*sizeof(*odds));
    memcpy(arr_sorted+odd_cnt, evens, even_cnt*sizeof(*evens));

    return 0;
}

int ascend(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int descend(const void *a, const void *b) {
    return *((int*)b) - *((int*)a);
}