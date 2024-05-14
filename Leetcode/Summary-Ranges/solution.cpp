#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.size() == 0) return {};

        vector<string> ans;
        int start = nums[0];
        long long end = nums[0]+1;

        for (int i=1; i<nums.size(); i++) {
            if (nums[i] != end) {
                if (start == end-1) {
                    ans.push_back(to_string(start));
                } else {
                    ans.push_back(to_string(start) + "->"+ to_string(end-1));
                }
                start = end = nums[i];
            }
            end++;
        }

        if (start == end-1) {
            ans.push_back(to_string(start));
        } else {
            ans.push_back(to_string(start) + "->"+ to_string(end-1));
        }

        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {0,2,3,4,6,8,9};

    vector<string> ans = solution.summaryRanges(nums);
}