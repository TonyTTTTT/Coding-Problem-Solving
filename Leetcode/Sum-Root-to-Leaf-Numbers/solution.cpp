#include <iostream>
#include <vector>
#include "../TreeNode.h"
using namespace std;

class Solution {
public:
    int sumNumbers(TreeNode* root, int num) {
        if (!root) return 0;
        
        num *= 10;
        num += root->val;

        if (!root->left && !root->right) {
            return num;
        }

        return sumNumbers(root->left, num) + sumNumbers(root->right, num);
    }

    int sumNumbers(TreeNode* root) {
        return sumNumbers(root, 0);
    }
};


int main() {
    Solution solution;
    TreeNode* root = new TreeNode(4, new TreeNode(9, new TreeNode(5), new TreeNode(1)), new TreeNode(0));

    int ans = solution.sumNumbers(root);
    __asm("nop");
}