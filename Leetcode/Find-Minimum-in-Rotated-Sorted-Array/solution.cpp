#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
	
        while(left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] < nums[right]) right = mid;
            else left = mid + 1;
        }

        return nums[left];
    }
};

int main() {
    Solution solution;
    vector<int> nums = {4,5,6,7,0,1,2};

    int ans = solution.findMin(nums);
}