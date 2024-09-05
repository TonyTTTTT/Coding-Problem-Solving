#include "../TreeNode.h"
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
    TreeNode* TraverseNDel(TreeNode* root, unordered_set<int>& to_delete, vector<TreeNode*>& ans) {
        if (!root) return nullptr;

        root->left = TraverseNDel(root->left, to_delete, ans);
        root->right = TraverseNDel(root->right, to_delete, ans);

        if (to_delete.count(root->val)) {
            if (root->left) ans.push_back(root->left);
            if (root->right) ans.push_back(root->right);
            return nullptr;
        }

        return root;
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        unordered_set<int> to_delete_set;
        for (auto num : to_delete) to_delete_set.insert(num);

        TreeNode* newRoot = TraverseNDel(root, to_delete_set, ans);
        if (newRoot) ans.push_back(newRoot);

        return ans;
    }
};

int main() {
    Solution sol;
    // TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3, new TreeNode(6), new TreeNode(7)));
    TreeNode* root = new TreeNode(5, new TreeNode(4, new TreeNode(3), new TreeNode(1)), new TreeNode(2));
    vector<int> to_delete = {5, 1};

    vector<TreeNode*> ans = sol.delNodes(root, to_delete);

    return 0;
}