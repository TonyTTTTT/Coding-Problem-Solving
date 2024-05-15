#include "../TreeNode.h"
#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    bool isSymmetric(TreeNode* left, TreeNode* right) {
        if (!left || !right) return left == right;

        if (left->val != right->val) return false;

        return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (!root->left || !root->right) return root->left == root->right;

        queue<TreeNode*> q;

        q.push(root->left);
        q.push(root->right);

        while (!q.empty()) {
            TreeNode* a = q.front(); q.pop();
            TreeNode* b = q.front(); q.pop();

            if (!a || !b) {
                if (a != b) return false;
                continue;
            }

            if (a->val != b->val) return false;

            q.push(a->left); q.push(b->right);

            q.push(a->right); q.push(b->left);
        }

        return true;
    }
};

int main() {
    Solution solution;
    TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)), new TreeNode(2, new TreeNode(4), new TreeNode(3)));

    bool ans = solution.isSymmetric(root);

    __asm("nop");
}