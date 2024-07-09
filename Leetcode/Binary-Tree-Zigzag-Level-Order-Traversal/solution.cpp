#include <vector>
#include <queue>
#include <algorithm>
#include "../TreeNode.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> curLevelSeq;
        int curLevel = 0;
        queue<TreeNode*> q;
        if (root) q.push(root);

        while (!q.empty()) {
            int curLevelSize = q.size();
            curLevelSeq.clear();

            for (int i=0; i<curLevelSize; i++) {
                TreeNode* cur = q.front(); q.pop();
                curLevelSeq.push_back(cur->val);

                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }

            if (curLevel % 2) reverse(curLevelSeq.begin(), curLevelSeq.end());
            ans.push_back(curLevelSeq);
            curLevel++;
        }

        return ans;
    }
};

int main() {
    Solution solution;
    TreeNode* root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));

    vector<vector<int>> ans = solution.zigzagLevelOrder(root);

    return 0;
}