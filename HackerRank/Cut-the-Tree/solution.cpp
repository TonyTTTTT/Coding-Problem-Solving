#include <vector>
#include <unordered_set>
#include <stdlib.h>
#include <algorithm>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    int sum=0;
    vector<TreeNode*> childs;
    
    TreeNode(int x) : val(x) {};
};

int caculateSum(TreeNode* root) {
    root->sum = root->val;
    
    for (auto child : root->childs) {
        root->sum += caculateSum(child);
    }
    
    return root->sum;
}

void findMinDiff(TreeNode* root, TreeNode* cur, int& ans) {
    int diff = abs((root->sum - cur->sum) - cur->sum);
    ans = min(ans, diff);
    
    for (auto child : cur->childs) {
        findMinDiff(root, child, ans);
    }
}

void convertToTree(TreeNode* cur, TreeNode* parent) {
    auto parentItr = find(cur->childs.begin(), cur->childs.end(), parent);
    if (parentItr != cur->childs.end()) cur->childs.erase(parentItr);

    for (auto child : cur->childs) {
        convertToTree(child, cur);
    }
}

int cutTheTree(vector<int> data, vector<vector<int>> edges) {
    queue<int> visitedId;
    unordered_set<int> visited;
    vector<TreeNode*> nodes;

    for (auto val : data) nodes.push_back(new TreeNode(val));
    TreeNode* root = nodes[edges[0][0]-1];

    for (auto edge : edges) {
        nodes[edge[0]-1]->childs.push_back(nodes[edge[1]-1]);
        nodes[edge[1]-1]->childs.push_back(nodes[edge[0]-1]);
    }

    convertToTree(root, root);
    
    caculateSum(root);
    
    int ans = INT_MAX;
    findMinDiff(root, root, ans);
    
    return ans;
}

int main() {
    // vector<int> data = {100, 200, 100, 500, 100, 600};
    vector<int> data = {205,573,985,242,830,514,592,263,142,915};
    // vector<vector<int>> edges = {{1,2}, {2,3}, {2,5}, {4,5}, {5,6}};
    vector<vector<int>> edges = {{2,8}, {10,5}, {1,7}, {6,9}, {4,3}, {8,10}, {5,1}, {7,6}, {9,4}};

    int ans = cutTheTree(data, edges);

    return 0;
}