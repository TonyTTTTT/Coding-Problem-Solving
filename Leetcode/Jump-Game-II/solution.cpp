#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;

        int curFarthest = 0;
        int curEnd = 0;
        int ans = 0;

        for (int i=0; i<n-1; i++) {
            curFarthest = max(curFarthest, i+nums[i]);
            if (i == curEnd) {
                ans++;
                curEnd = curFarthest;
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2,3,1,1,4};

    int ans = solution.jump(nums);
}