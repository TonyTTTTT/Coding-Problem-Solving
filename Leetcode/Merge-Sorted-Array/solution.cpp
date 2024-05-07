#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx1=m-1, idx2=n-1;

        int current = m+n-1;

        while (idx2>=0) {
            if (idx1>=0 && nums1[idx1] >= nums2[idx2]) {
                nums1[current--] = nums1[idx1--];
            } else {
                nums1[current--] = nums2[idx2--];
            }
        }
    }
};

int main() {
    vector<int> nums1 = {0};
    int m = 0;
    vector<int> nums2 = {1};
    int n = 1;

    Solution solution;
    solution.merge(nums1, m, nums2, n);
    __asm("nop");
}