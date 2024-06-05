#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums) {
        int minSoFar = nums[0];
        int minEndHere=0;

        for (int i=0; i<nums.size(); i++) {
            minEndHere += nums[i];
            minEndHere = min(minEndHere, nums[i]);
            minSoFar = min(minSoFar, minEndHere);
        }

        return minSoFar;
    }

    int maxSubarraySumCircular(vector<int>& nums) {
        int maxSoFar=nums[0], maxEndHere=0;
        int allSum = 0;

        for (int i=0; i<nums.size(); i++) {
            allSum += nums[i];
            maxEndHere = max(maxEndHere+nums[i], nums[i]);
            maxSoFar = max(maxSoFar, maxEndHere);
        }
        
        if (maxSoFar > 0) {
            int minSoFar=nums[0], minEndHere=0;

            for (int i=0; i<nums.size(); i++) {
                minEndHere = min(minEndHere+nums[i], nums[i]);
                minSoFar = min(minSoFar, minEndHere);
            }

            maxSoFar = max(maxSoFar, allSum - minSoFar);
        }

        return maxSoFar;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {9,7,-6,7,9,-10,5,9,0,-1};

    int ans = solution.maxSubarraySumCircular(nums);

    __asm("nop");
}