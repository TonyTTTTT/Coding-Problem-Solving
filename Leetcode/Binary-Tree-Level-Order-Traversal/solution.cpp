#include <iostream>
#include <vector>
#include "../TreeNode.h"
#include <queue>
using namespace std;

class Solution {
public:
    void levelOrder(TreeNode* root, vector<vector<int>>& ans, int level) {
        if (!root) return;

        if (level+1 > ans.size()) {
            ans.push_back({});
        }
        ans[level].push_back(root->val);

        levelOrder(root->left, ans, level+1);
        levelOrder(root->right, ans, level+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;

        if (root != nullptr) q.push(root);

        while (!q.empty()) {
            int qSize = q.size();
            vector<int> subV;
            for (int i=0; i<qSize; i++) {
                if (q.front()->left != nullptr) q.push(q.front()->left);
                if (q.front()->right != nullptr) q.push(q.front()->right);
                subV.push_back(q.front()->val);
                q.pop();
            }
            ans.push_back(subV);
        }

        return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    // TreeNode* root = nullptr;
    Solution solution;

    vector<vector<int>> ans = solution.levelOrder(root);
}