#include <vector>
#include <map>
#include "../TreeNode.h"
using namespace std;


class Solution {
public:
    map<int, vector<TreeNode*>> mem;
    vector<TreeNode*> allPossibleFBT(int n) {
        if (n==1) return vector<TreeNode*>{new TreeNode(0)};

        vector<TreeNode*> ans;
        if (n%2 == 0) return ans;

        vector<vector<TreeNode*>> subFBTs;
        for (int i=1; i<n; i+=2) {
            if (mem.find(i) == mem.end()) {
                vector<TreeNode*> subFBT = allPossibleFBT(i);
                mem.insert(make_pair(i, subFBT));
            }
            subFBTs.push_back(mem[i]);
        }

        for (int i=0; i<subFBTs.size(); i++) {
            for (int j=0; j<subFBTs[i].size(); j++) {
                for (int k=0; k<subFBTs[subFBTs.size()-1-i].size(); k++) {
                    TreeNode* root = new TreeNode();
                    root->left = subFBTs[i][j];
                    root->right = subFBTs[subFBTs.size()-1-i][k];
                    ans.push_back(root);
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;
    int n = 7;

    vector<TreeNode*> ans = solution.allPossibleFBT(n);
}