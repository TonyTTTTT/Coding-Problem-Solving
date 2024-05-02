#include <iostream>
#include <vector>
#include <algorithm>
#include "../TreeNode.h"
using namespace std;

class Solution {
public:
    TreeNode* buildTree(auto preorderS, auto inorderS, auto inorderE) {
        if (inorderS==inorderE) return nullptr;

        TreeNode* root = new TreeNode(*preorderS);

        auto it = find(inorderS, inorderE, *preorderS);
        int rootIdx = it - inorderS;

        root->left = buildTree(preorderS+1, inorderS, inorderS+rootIdx);
        root->right = buildTree(preorderS+1+rootIdx, inorderS+rootIdx+1, inorderE);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder.begin(), inorder.begin(), inorder.end());
    }
};

int main() {
    Solution solution;
    vector<int> preorder{3,9,20,15,7};
    vector<int> inorder{9,3,15,20,7};

    TreeNode* ans = solution.buildTree(preorder, inorder);
}