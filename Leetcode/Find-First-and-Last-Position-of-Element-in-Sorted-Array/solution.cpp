#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    int binSearch(vector<int>& nums, int l, int r, int target) {
        while (l<=r) {
            int mid = (l+r)/2;

            if (nums[mid] == target)  mid;
            else if (nums[mid] > target) r = mid-1;
            else l = mid+1;
        }

        return -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size()==0) return {-1, -1};

        int lIdx = -1;
        int l=0, r=nums.size()-1;

        while (l<r) {
            int mid = (l+r)/2;

            if (nums[mid] >= target)  r = mid;
            else l = mid+1;
        }
        if (nums[l] == target) lIdx = l;
        else return {-1, -1};

        int rIdx;
        r=nums.size()-1;

        while(l<r) {
            int mid = ceil((double)(l+r)/2);

            if (target >= nums[mid]) l = mid;
            else r = mid-1;
        }
        if (nums[l]==target) rIdx = l;

        return {lIdx, rIdx};     
    }
};

int main() {
    Solution solution;
    vector<int> nums = {};
    int target = 8;

    vector<int> ans = solution.searchRange(nums, target);
    __asm("nop");
}