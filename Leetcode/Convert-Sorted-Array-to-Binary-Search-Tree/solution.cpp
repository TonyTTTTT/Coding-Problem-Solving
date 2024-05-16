#include <vector>
#include "../TreeNode.h"
using namespace std;


class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums, int l, int r) {
        if (l > r) return nullptr;

        int mid = (l + r) / 2;

        TreeNode* root = new TreeNode(nums[mid]);

        root->left = sortedArrayToBST(nums, l, mid-1);
        root->right = sortedArrayToBST(nums, mid+1, r);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size()-1);
    }
};

int main() {
    Solution solution;
    vector<int> nums = {-10,-3,0,5,9};

    TreeNode* ans = solution.sortedArrayToBST(nums);

    __asm("nop");
}