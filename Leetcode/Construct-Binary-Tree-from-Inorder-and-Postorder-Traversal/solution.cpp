#include <vector>
#include "../TreeNode.h"
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
    unordered_map<int, int> inorderIdxOf;
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postRootIdx) {
        if (inStart > inEnd) return nullptr;

        TreeNode* root = new TreeNode(postorder[postRootIdx]);

        int inRootIdx = inorderIdxOf[root->val];

        root->right = buildTree(inorder, postorder, inRootIdx+1, inEnd, postRootIdx-1);

        int rightTreeSize = inEnd - inRootIdx;
        root->left = buildTree(inorder, postorder, inStart, inRootIdx-1, postRootIdx-rightTreeSize-1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i=0; i<inorder.size(); i++) inorderIdxOf[inorder[i]] = i;

        return buildTree(inorder, postorder, 0, inorder.size()-1, postorder.size()-1);    
    }
};

int main() {
    Solution solution;

    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};

    TreeNode* ans = solution.buildTree(inorder, postorder);
}