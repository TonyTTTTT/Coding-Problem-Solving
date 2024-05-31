#include "../TreeNode.h"
#include <stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    void inOrder(TreeNode* root, int& ans, int& last) {
        if (!root) return;

        inOrder(root->left, ans, last);

        if (root->val - last < ans) ans = root->val - last;

        last = root->val;

        inOrder(root->right, ans, last);

        return;
    }

    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        int last = -100001;

        inOrder(root, ans, last);

        return ans;
    }
};


int main() {
    Solution solution;
    TreeNode* root = new TreeNode(4, new TreeNode(2, new TreeNode(1), new TreeNode(3)), new TreeNode(6));

    int ans = solution.getMinimumDifference(root);
}