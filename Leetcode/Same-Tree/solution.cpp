#include "../TreeNode.h"
using namespace std;

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p || !q) {
            return p==nullptr && q==nullptr;
        }
        if (p->val != q->val) return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main() {
    Solution solution;
    TreeNode* p = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    TreeNode* q = new TreeNode(1, new TreeNode(2, new TreeNode(2), nullptr), new TreeNode(3));

    bool ans = solution.isSameTree(p, q);
    __asm("nop");
}