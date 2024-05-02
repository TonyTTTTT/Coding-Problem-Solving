#include <iostream>
#include <vector>
#include <algorithm>
#include "../TreeNode.h"
using namespace std;

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() && inorder.empty()) return nullptr;

        TreeNode* root = new TreeNode(preorder[0]);

        auto it = find(inorder.begin(), inorder.end(), preorder[0]);
        int rootIdx = it - inorder.begin();

        vector<int> preorderLeft{preorder.begin()+1, preorder.begin()+1+rootIdx};
        vector<int> inorderLeft{inorder.begin(), inorder.begin()+rootIdx};
        vector<int> preorderRight{preorder.begin()+1+rootIdx, preorder.end()};
        vector<int> inorderRight{inorder.begin()+rootIdx+1, inorder.end()};

        root->left = buildTree(preorderLeft, inorderLeft);
        root->right = buildTree(preorderRight, inorderRight);

        return root;
    }
};

int main() {
    Solution solution;
    vector<int> preorder{3,9,20,15,7};
    vector<int> inorder{9,3,15,20,7};

    TreeNode* ans = solution.buildTree(preorder, inorder);
}