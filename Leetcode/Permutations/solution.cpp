#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void backTracking(vector<vector<int>>& ans, vector<int>& subVec, vector<int>& nums) {
        if (subVec.size() == nums.size()) ans.push_back(subVec);

        for (int i=0; i<nums.size(); i++) {
            if (find(subVec.begin(), subVec.end(), nums[i]) != subVec.end()) continue;
            subVec.push_back(nums[i]);
            backTracking(ans, subVec, nums);
            subVec.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subVec;
        backTracking(ans, subVec, nums);

        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> ans = solution.permute(nums);
    __asm("nop");
}