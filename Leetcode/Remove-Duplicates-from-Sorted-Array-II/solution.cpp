#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>::iterator current = nums.begin();

        while (current < nums.end()-2) {
            vector<int>::iterator shift = current+2;

            while (*current==*shift && shift<nums.end()) {
                shift = nums.erase(shift);
            }
            current++;
        }

        return nums.end() - nums.begin();
    }
};

int main() {
    Solution solution;
    vector<int> nums{1,1,1};

    int ans = solution.removeDuplicates(nums);
    __asm("nop");
}