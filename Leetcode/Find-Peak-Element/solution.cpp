#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l=0, r=nums.size()-1;
        int mid;

        while (l < r) {
            mid = (l+r)/2;
            
            if ((mid-1<0 || nums[mid-1]<nums[mid]) && (mid+1==nums.size() || nums[mid]>nums[mid+1])) return mid;
            else if (mid-1 >= 0 && nums[mid-1] > nums[mid]) r = mid-1;
            else l = mid+1;
        }

        return l;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1,2};

    int ans = solution.findPeakElement(nums);

    __asm("nop");
}