#include <vector>
#include <stdlib.h>
#include <climits>
using namespace std;

class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long ans = INT_MIN;
        long long tmp;
        int n = nums.size();

        for (int len=k; len<=n; len+=k) {
            tmp = 0;
            int l=0, r=0;
            while (r < len) tmp += nums[r++];
            while (r < n) {
                ans = max(ans, tmp);
                tmp = tmp - nums[l++] + nums[r++];
            }
            ans = max(ans, tmp);
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,2};
    int k = 1;

    long long ans = sol.maxSubarraySum(nums, k);

    return 0;
}