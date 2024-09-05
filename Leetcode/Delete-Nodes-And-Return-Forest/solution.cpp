#include "../TreeNode.h"
#include <vector>
using namespace std;

class Solution {
    bool findNDel(TreeNode* root, const int& target_num, vector<TreeNode*>& ans) {
        if (root->left) {
            if (root->left->val == target_num) {
                if (root->left->left) ans.push_back(root->left->left);
                if (root->left->right) ans.push_back(root->left->right);
                root->left = nullptr;
                return true;
            }
            if(findNDel(root->left, target_num, ans)) return true;
        }
        if (root->right) {
            if(root->right->val == target_num) {
                if (root->right->left) ans.push_back(root->right->left);
                if (root->right->right) ans.push_back(root->right->right);
                root->right = nullptr;
                return true;
            }
            if (findNDel(root->right, target_num, ans)) return true;
        }

        return false;
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans = {root};

        for (auto target_num : to_delete) {
            for (auto itr=ans.begin(); itr!=ans.end(); itr++) {
                TreeNode* curRoot = *itr;
                if (curRoot->val == target_num) {
                    ans.erase(itr);
                    if (curRoot->left) ans.push_back(curRoot->left);
                    if (curRoot->right) ans.push_back(curRoot->right);
                    break;
                } else if (findNDel(curRoot, target_num, ans)) break;
            }
        }

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