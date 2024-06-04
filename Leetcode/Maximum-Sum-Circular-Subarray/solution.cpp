#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int startIdx=0, curIdx=0;
        int ans=INT_MIN, curSum=0;

        while (startIdx <= curIdx) {
            startIdx = curIdx;
            curSum = 0;
            while (curSum >= 0) {
                curSum += nums[curIdx];
                if (curSum > ans) ans = curSum;

                curIdx = (curIdx+1) % nums.size();
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {5,-3,5};

    int ans = solution.maxSubarraySumCircular(nums);
}