#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        if (nums.size() == 1) return {{nums[0]}};

        for (int i=0; i<nums.size(); i++) {
            vector<int> subNums = nums;
            subNums.erase(subNums.begin()+i);

            vector<vector<int>> subAns = permute(subNums);
            for (auto x : subAns) {
                x.push_back(nums[i]);
                ans.push_back(x);
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1};

    vector<vector<int>> ans = solution.permute(nums);
    __asm("nop");
}