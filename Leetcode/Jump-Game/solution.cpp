#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int needJump = 1;
        
        for (int i=nums.size()-2; i>=0; i--) {
            if (nums[i] >= needJump){
                needJump = 1;
            } else {
                needJump++;
            }
        }

        return needJump == 1;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3,2,1,0,4};

    bool ans = solution.canJump(nums);
    __asm("nop");
}