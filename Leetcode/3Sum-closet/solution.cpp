#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int sum, diff, i, j, k;
        sort(nums.begin(), nums.end());
        int ans = nums[0] + nums[1] + nums[nums.size()-1];

        for (i=0; i<nums.size(); i++) {
            j = i+1;
            k = nums.size() - 1;
            while (j < k) {
                sum  = nums[i] + nums[j] + nums[k];
                diff = sum - target;
                if (abs(diff) < abs(ans - target)) {
                    ans = sum;
                }
                if (diff <= 0) {
                    j++;
                } else { // diff > 0
                    k--;
                }
            }
        }

        return ans;
    }
};

int main () {
    vector<int> nums = {0, 0, 0, 0};
    int target = 1;
    Solution solution;

    int ans = solution.threeSumClosest(nums, target);

    cout<<ans<<endl;

    return 0;
}