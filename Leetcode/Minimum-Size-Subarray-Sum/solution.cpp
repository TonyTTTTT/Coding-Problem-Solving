#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> mySort(vector<int>& nums) {
        if (nums.size() <= 1) return nums;

        int pv = nums.size()/2;
        vector<int> left;
        vector<int> right;

        for (int i=0; i<nums.size(); i++) {
            if (i==pv) continue;
            if (nums[i]<=nums[pv]) {
                left.push_back(nums[i]);
            } else {
                right.push_back(nums[i]);
            }
        }

        left = mySort(left);
        right = mySort(right);
        left.push_back(nums[pv]);
        left.insert(left.end(), right.begin(), right.end());

        return left;
    }

    int minSubArrayLen(int target, vector<int>& nums) {
        int total = 0;
        int ans = nums.size()+1;

        int l=0, r=0;

        while(l<nums.size() || r<nums.size()) {
            if (total<target) {
                if (r==nums.size()) break;
                total += nums[r++];
            } else {
                total -= nums[l++];
            }

            if (total >= target) {
                ans = min(ans, r-l);
            }
        }

        if (ans == nums.size()+1) ans = 0;

        return ans;
    }
};

int main() {
    Solution solution;
    int target = 11;
    vector<int> nums{1,1,1,1,1,1,1,1};

    int ans = solution.minSubArrayLen(target, nums);
}