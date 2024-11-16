#include <stdbool.h>

void push_back(int **v, int *size, int x) {
    *v = realloc(*v, (*size + 1) * sizeof(int));
    (*v)[*size] = x;
    (*size)++;
}

int** findDifference(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    bool num_exist1[2001] = {false};
    bool num_exist2[2001] = {false};

    for (int i=0; i<nums1Size; i++) num_exist1[nums1[i] + 1000] = true;
    for (int i=0; i<nums2Size; i++) num_exist2[nums2[i] + 1000] = true;

    int in1not2_size = 0;
    int in2not1_size = 0;
    int * in1not2 = malloc(0);
    int * in2not1 = malloc(0);

    for (int i=0; i<2001; i++) {
        if (num_exist1[i] && !num_exist2[i]) push_back(&in1not2, &in1not2_size, i-1000);
        else if (num_exist2[i] && !num_exist1[i]) push_back(&in2not1, &in2not1_size, i-1000);
    }

    int ** ans = malloc(sizeof(int*) * 2);

    return ans;
}

int main() {
    int nums1[] = {1,2,3};
    int nums2[] = {2,4,6};
    int nums1Size = 3;
    int nums2Size = 3;

    int ** ans = findDifference(nums1, nums1Size, nums2, nums2Size);

    return 0;
}