#include <iostream>
#include <vector>
#include "../TreeNode.h"
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};

        vector<vector<int>> left = levelOrder(root->left);
        vector<vector<int>> right = levelOrder(root->right);

        int longerSize = max(left.size(), right.size());

        for (int i=0; i<longerSize; i++) {
            if (i >= left.size()) {
                left.push_back(right[i]);
            } else if (i >= right.size()){
                break;
            } else {
                left[i].insert(left[i].end(), right[i].begin(), right[i].end());
            }
        }

        left.insert(left.begin(), {root->val});

        return left;
    }
};

int main() {
    // TreeNode* root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    TreeNode* root = nullptr;
    Solution solution;

    vector<vector<int>> ans = solution.levelOrder(root);
}