#include "../TreeNode.h"
#include <iostream>
using namespace std;

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;

        int l = maxDepth(root->left);
        int r = maxDepth(root->right);

        return max(l, r) + 1;
    }
};

int main() {
    Solution solution;
    TreeNode* root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));

    int ans = solution.maxDepth(root);
}