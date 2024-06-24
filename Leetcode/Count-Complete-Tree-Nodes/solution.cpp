#include "../TreeNode.h"
#include <math.h>

class Solution {
public:
    bool findLastLevelRightmost(TreeNode* root, int curH, int h, int& lack) {
        if (!root) {
            lack++;
            return false;
        }
        if (curH == h) return true;

        if (findLastLevelRightmost(root->right, curH+1, h, lack)) return true;
        if (findLastLevelRightmost(root->left, curH+1, h, lack)) return true;

        return false;
    }
    int countNodes(TreeNode* root) {
        int lh = 0, rh = 0;
        for (TreeNode* tmp=root; tmp; tmp=tmp->left) lh++;
        for (TreeNode* tmp=root; tmp; tmp=tmp->right) rh++;

        if (lh == rh) return (1 << lh) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

int main() {
    Solution solution;
    TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3, new TreeNode(6), nullptr));

    int ans = solution.countNodes(root);
}