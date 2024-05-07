#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = INT_MAX;
        int cnt = 0;

        for (int i=0; i<nums.size(); i++) {
            if (cnt==0) {
                ans = nums[i];
                cnt++;
            } else if (nums[i] == ans) {
                cnt++;
            } else { //cnt>0 and nums[i]!=ans
                cnt--;
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2,2,1,1,1,2,2};

    int ans = solution.majorityElement(nums);
    __asm("nop");
}