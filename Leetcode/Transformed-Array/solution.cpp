#include <vector>
using namespace std;

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        for (int i=0; i<n; i++) {
            int tmp = (i+(nums[i]%n)+n) % n;
            ans[i] = nums[tmp];
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {5,-9,8,7,-3,9,0};

    vector<int> ans = sol.constructTransformedArray(nums);

    return 0;
}