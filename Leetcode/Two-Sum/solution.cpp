#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> m;

        for (int i=0; i<nums.size(); i++) {
            int want = target - nums[i];
            unordered_map<int, int>::iterator itr = m.find(want);
            if (itr != m.end()) {
                ans.push_back(i);
                ans.push_back(itr->second);
                break;
            } else {
                m[nums[i]] = i;
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;
    int target = 9;
    vector<int> nums{2,7,11,15};

    vector<int> ans = solution.twoSum(nums, target);
}