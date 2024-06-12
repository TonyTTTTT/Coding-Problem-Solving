#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = nums[0];

        for (int i=1; i<nums.size(); i++) {
            ans = !(ans | nums[i]);
        }

        ans = !ans;

        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {0,1,0,1,0,1,99};

    int ans = solution.singleNumber(nums);
}