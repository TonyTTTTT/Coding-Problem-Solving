#include <iostream>
#include <vector>
#include <algorithm>
#include "../QuadTreeNode.h"
using namespace std;

class Solution {
public:
    Node* construct(vector<vector<int>>& grid, int mS, int nS, int len) {
        int cnt = 0;
        for (int i=mS; i<mS+len; i++) {
            cnt += count(grid[i].begin()+nS, grid[i].begin()+nS+len, 0);
        }
        if (cnt == len*len) return new Node(0, 1);
        else if (cnt == 0) return new Node(1, 1);

        Node* root = new Node(1, 0);


        root->topLeft = construct(grid, mS, nS, len/2);
        root->topRight = construct(grid, mS, nS+len/2, len/2);
        root->bottomLeft = construct(grid, mS+len/2, nS, len/2);
        root->bottomRight = construct(grid, mS+len/2, nS+len/2, len/2);

        return root;
    }

    Node* construct(vector<vector<int>>& grid) {
        return construct(grid, 0, 0, grid.size());
    }
};

int main() {
    vector<vector<int>> grid = {
        {1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0}
    };
    Solution solution;

    Node* ans = solution.construct(grid);
}