#include <vector>
#include <unordered_set>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int ans = 0;
        int curlong;

        for (int i=0; i<nums.size(); i++) {
            s.insert(nums[i]);
        }

        for (int num : s) {
            if (!s.count(num-1)) {
                curlong = 1;
                while (s.count(num+curlong)) {
                    curlong++;
                }
                if (curlong > ans) ans = curlong;
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {0,3,7,2,5,8,4,6,0,1};

    int ans = solution.longestConsecutive(nums);
}