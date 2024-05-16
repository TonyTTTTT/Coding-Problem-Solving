#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=0;

        for (int i=1; i<nums.size(); i++) {
            if (nums[i] != nums[k]) {
                k++;
                nums[k] = nums[i];
            }
        }

        return k+1;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};

    int ans = solution.removeDuplicates(nums);
}