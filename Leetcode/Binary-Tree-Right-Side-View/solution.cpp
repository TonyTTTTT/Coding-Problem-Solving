#include <vector>
#include "../TreeNode.h"
#include <queue>
using namespace std;


class Solution {
public:
    void preOrder(TreeNode* root, vector<int>& ans, int lvl) {
        if (!root) return;

        if (ans.size() == lvl) ans.push_back(root->val);

        preOrder(root->right, ans, lvl+1);
        preOrder(root->left, ans, lvl+1);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        preOrder(root, ans, 0);

        return ans;
    }
    // vector<int> rightSideView(TreeNode* root) {
    //     vector<int> ans;
    //     queue<TreeNode*> q;
    //     if (root) q.push(root);

    //     while (!q.empty()) {
    //         int curSize = q.size();

    //         TreeNode* node;
    //         for (int i=0; i<curSize; i++) {
    //             node = q.front(); q.pop();
    //             if (node->left) q.push(node->left);
    //             if (node->right) q.push(node->right);
    //         }
    //         ans.push_back(node->val);
    //     }

    //     return ans;
    // }
};


int main() {
    Solution solution;
    TreeNode* root = new TreeNode(1, new TreeNode(2, nullptr, new TreeNode(5)), new TreeNode(3, nullptr, new TreeNode(4)));

    vector<int> ans = solution.rightSideView(root);
}