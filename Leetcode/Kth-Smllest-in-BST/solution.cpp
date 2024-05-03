#include <iostream>
#include <vector>
#include "../TreeNode.h"
using namespace std;

class Solution {
public:
    void inorderTraverse(TreeNode* root, vector<int>& res) {
        if (!root) return;

        inorderTraverse(root->left, res);
        res.push_back(root->val);
        inorderTraverse(root->right, res);
    }
    int inorderTraverseStop(TreeNode* root, int k, int& cnt) {
        if (!root) return -1;

        int ans = inorderTraverseStop(root->left, k, cnt);
        if (ans != -1) return ans;

        cnt++;
        if (cnt==k) return root->val;

        ans = inorderTraverseStop(root->right, k, cnt);
        if (ans != -1) return ans;

        return -1;
    }
    int kthSmallest(TreeNode* root, int k) {
        // vector<int> inorder;
        int cnt = 0;
        int ans = inorderTraverseStop(root, k, cnt);

        return ans;
    }
};

int main() {
    Solution solution;
    TreeNode* root = new TreeNode(5, new TreeNode(3, new TreeNode(2, new TreeNode(1), nullptr), new TreeNode(4)), new TreeNode(6));
    int k = 3;

    int ans = solution.kthSmallest(root, k);
}