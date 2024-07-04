#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> LIS;
        LIS.push_back(nums[0]);

        for (int i=1; i<nums.size(); i++) {
            if (nums[i] > LIS.back()) LIS.push_back(nums[i]);
            else { //nums[i] <= LIS.back()
                int replacedIdx = lower_bound(LIS.begin(), LIS.end(), nums[i]) - LIS.begin();
                LIS[replacedIdx] = nums[i];
            }
        }

        return LIS.size();
    }
};

int main() {
    Solution solution;
    vector<int> nums = {10,9,2,5,3,7,101,18};

    int ans = solution.lengthOfLIS(nums);

    return 0;
}