#include <stdlib.h>

int* push_back(int* ary, int size, int x) {
    int *tmp = (int*)realloc(ary, (size + 1) * sizeof(int));
    if (!tmp) {
        perror("realloc() fail!");
        exit(1);
    }
    tmp[size] = x;

    return tmp;
}

int longestSubarray(int* nums, int numsSize) {
    int idx = 0;
    int lenArySize = 0;
    int *lenAry = (int*)malloc(sizeof(int) * numsSize);
    int zeroCnt = 0;

    while (idx < numsSize && nums[idx] == 0) {
        idx++;
        zeroCnt++;
    }

    while (idx < numsSize) {
        int cnt = 0;
        while (idx < numsSize && nums[idx] == 1) {
            cnt++;
            idx++;
        }
        // lenAry[lenArySize++] = cnt;
        lenAry = push_back(lenAry, lenArySize, cnt);
        lenArySize++;

        cnt = 0;
        while (idx < numsSize && nums[idx] == 0) {
            cnt++;
            idx++;
            zeroCnt++;
        }
        if (cnt != 0) {
            // lenAry[lenArySize++] = cnt;
            lenAry = push_back(lenAry, lenArySize, cnt);
            lenArySize++;
        }
    }

    if (lenArySize == 0) return 0;
    else if (lenArySize == 1 && zeroCnt == 0) return lenAry[0] - 1;

    int ans = lenAry[0];
    
    for (int i=1; i<lenArySize-1; i+=2) {
        if (lenAry[i] == 1) {
            ans = fmax(ans, lenAry[i-1] + lenAry[i+1]);
        }
        else { // lenAry[i] > 1
            ans = fmax(ans, lenAry[i+1]);
        }
    }

    return ans;
}

int main() {
    int nums[] = {1, 1, 0, 1};
    int numsSize = 4;

    int ans = longestSubarray(nums, numsSize);

    return 0;
}