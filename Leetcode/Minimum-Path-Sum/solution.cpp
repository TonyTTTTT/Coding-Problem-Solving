#include <vector>
using namespace std;


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> dp(n, __INT_MAX__);

        dp[0] = grid[0][0];

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                int left = __INT_MAX__;
                int up = __INT_MAX__;
                if (j > 0) left = dp[j-1];
                if (i > 0) up = dp[j];

                if (i > 0 || j > 0) dp[j] = grid[i][j] + min(left, up);
            }
        }

        return dp[n-1];
    }
};

int main() {
    Solution solution;
    vector<vector<int>> grid = {
        {1,3,1},{1,5,1},{4,2,1}
    };

    int ans = solution.minPathSum(grid);
}