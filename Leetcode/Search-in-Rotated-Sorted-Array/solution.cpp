#include <vector>
using namespace std;

class Solution {
public:
    int binSearch(vector<int>& nums, int left, int right, int target) {
        while (left <= right) {
            int mid = (left+right) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }

        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n-1;

        while (left < right) {
            int mid = (left+right) / 2;

            if (nums[mid] > nums[right]) left = mid+1;
            else right = mid; //can't assign right=mid-1, because mid might be the startIdx
        }

        int startIdx = left;

        int ans = binSearch(nums, 0, startIdx-1, target);
        if (ans == -1) ans = binSearch(nums, startIdx, n-1, target);

        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {5,1,3};
    int target = 0;

    int ans = solution.search(nums, target);

    return 0;
}