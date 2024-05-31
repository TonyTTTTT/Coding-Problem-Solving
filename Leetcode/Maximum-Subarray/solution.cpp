#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curSum = 0;
        int ans = smallest;

        for (int i=0; i<nums.size(); i++) {
            curSum += nums[i];
            
            if (curSum < nums[i]) curSum = nums[i];

            if (curSum > ans) ans = curSum;
        }

        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {-2,-3,-1,-5};

    int ans = solution.maxSubArray(nums);
}