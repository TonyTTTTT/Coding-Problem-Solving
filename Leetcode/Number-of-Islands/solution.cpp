#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void diffuse(vector<vector<char>>& grid, int i, int j) {
        if (grid[i][j] == '0') return;

        grid[i][j] = '0';

        if (i != 0) {
            diffuse(grid, i-1, j);
        }
        if (j != 0) {
            diffuse(grid, i, j-1);
        }
        if (i != grid.size()-1) {
            diffuse(grid, i+1, j);
        }
        if (j != grid[0].size()-1) {
            diffuse(grid, i, j+1);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;

        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    ans++;
                    diffuse(grid, i, j);
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;
    vector<vector<char>> grid = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };

    int ans = solution.numIslands(grid);
}