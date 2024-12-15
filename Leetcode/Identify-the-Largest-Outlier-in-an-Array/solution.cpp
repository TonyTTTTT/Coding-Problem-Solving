#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stdlib.h>
#include <vector>
using namespace std;

class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        int n = nums.size();
        unordered_map<int, int> s;

        for (int i=0; i<n; i++) {
            sum += nums[i];
            s[nums[i]] = i;
        }
        
        for (int i=n-1; i>=0; i--) {
            int tmp = sum - nums[i];
            if (tmp % 2 == 0 && s.count(tmp/2) && s[tmp/2]!=i) return nums[i];
        }

        return __INT32_MAX__;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {6,-31,50,-35,41,37,-42,13};

    int ans = sol.getLargestOutlier(nums);

    return 0;
}