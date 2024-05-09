#include <iostream>
#include "../TreeNode.h"
#include <vector>
using namespace std;

class Solution {
public:
    TreeNode* prev = nullptr;
    void flatten(TreeNode* root) {
        if (root == nullptr) return;

        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = nullptr;

        prev = root;
        return;
    }
};

int main() {
    Solution solution;
    TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)), new TreeNode(5, nullptr, new TreeNode(6)));

    solution.flatten(root);
    __asm("nop");
}