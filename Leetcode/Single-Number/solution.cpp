#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;

        for (auto num : nums) {
            ans ^= num;
        }

        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {4,1,2,3,1,2,4};

    int ans = solution.singleNumber(nums);
}