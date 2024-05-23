#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        
        int dp[nums.size()];

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i=2; i<nums.size(); i++) {
            dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
        }

        return dp[nums.size()-1];
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2,7,9,3,1};

    int ans = solution.rob(nums);
}