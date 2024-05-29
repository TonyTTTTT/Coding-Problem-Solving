#include "../TreeNode.h"
using namespace std;

struct ReturnData {
    bool containP = false;
    bool containQ = false;
    TreeNode* ans = nullptr;
};


class Solution {
public:
    ReturnData solve(TreeNode* root, TreeNode* p, TreeNode* q) {
        ReturnData left;
        if (root->left) {
            left = solve(root->left, p, q);
            if (left.ans) return left;
        }
        ReturnData right;
        if (root->right) {
            right = solve(root->right, p, q);
            if (right.ans) return right;
        }

        ReturnData r;
        r.containP = left.containP || right.containP || root->val == p->val;
        r.containQ = left.containQ || right.containQ || root->val == q->val;
        
        if (r.containP && r.containQ) r.ans = root;

        return r;
    }

    bool contain(TreeNode* root, TreeNode* target) {
        if (!root) return false;

        if (root->val == target->val) return true;

        return contain(root->left, target) || contain(root->right, target);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root==p || root==q) return root;

        TreeNode* leftAncestor = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightAncestor = lowestCommonAncestor(root->right, p, q);

        if (leftAncestor && rightAncestor) return root;
        
        return leftAncestor ? leftAncestor : rightAncestor;
    }
};

int main() {
    Solution solution;
    TreeNode* q = new TreeNode(4);
    TreeNode* p = new TreeNode(5, new TreeNode(6), new TreeNode(2, new TreeNode(7), q));
    TreeNode* k = new TreeNode(1, new TreeNode(0), new TreeNode(8));

    TreeNode* root = new TreeNode(3, p, k);

    TreeNode* ans = solution.lowestCommonAncestor(root, p, q);

    __asm("nop");
}