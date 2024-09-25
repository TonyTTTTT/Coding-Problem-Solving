#include "../TreeNode.h"
#include <iostream>
#include <algorithm>
using namespace std;


class Solution {
    void traverse(TreeNode* root, int& s, int& d, bool& containS, bool& containD, TreeNode*& ca) {
        if (!root) return;

        traverse(root->left, s, d, containS, containD, ca);
        traverse(root->right, s, d, containS, containD, ca);

        if (root->val == s) containS = true;
        if (root->val == d) containD = true;

        if (ca == nullptr && containS && containD) ca = root;
    }

    bool find(TreeNode* root, int target, string& path) {
        if (!root) return false;
        if (root->val == target) return true;

        bool leftContain = find(root->left, target, path);
        bool rightContain = find(root->right, target, path);
        if (leftContain) path.push_back('L');
        if (rightContain) path.push_back('R');
        
        return leftContain || rightContain;
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* ca = nullptr;
        bool containD = false;
        bool containS = false;

        traverse(root, startValue, destValue, containS, containD, ca);

        string tmp = "";
        find(ca, startValue, tmp);

        string ans = string(tmp.size(), 'U');

        tmp = "";
        find(ca, destValue, tmp);
        reverse(tmp.begin(), tmp.end());

        ans += tmp;

        return ans;
    }
};

int main() {
    Solution sol;
    TreeNode* root = new TreeNode(5, new TreeNode(1, new TreeNode(3), nullptr), new TreeNode(2, new TreeNode(6), new TreeNode(4)));
    int startValue = 3;
    int destValue = 6;

    string ans = sol.getDirections(root, startValue, destValue);

    return 0;
}