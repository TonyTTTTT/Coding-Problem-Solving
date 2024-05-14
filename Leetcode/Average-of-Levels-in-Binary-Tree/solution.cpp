#include <vector>
#include "../TreeNode.h"
#include <queue>
using namespace std;

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            double sum = 0;
            int nodeNum = q.size();

            for (int i=0; i<nodeNum; i++) {
                TreeNode* current = q.front();

                sum += current->val;

                if (current->left) q.push(current->left);
                if (current->right) q.push(current->right);

                q.pop();
            }

            sum /= nodeNum;
            ans.push_back(sum);
        }

        return ans;
    }
};

int main() {
    Solution solution;
    TreeNode* root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));

    vector<double> ans = solution.averageOfLevels(root);
}