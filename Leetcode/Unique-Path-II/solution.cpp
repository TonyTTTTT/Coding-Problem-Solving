#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> dp(n);
        dp[0] = 1;
        
        for (int r=0; r<m; r++) {
            for (int c=0; c<n; c++) {
                if (obstacleGrid[r][c] == 1) dp[c] = 0;
                else if (c > 0) dp[c] += dp[c-1];
            }
        }

        return dp[n-1];
    }
};

int main() {
    Solution solution;
    vector<vector<int>> obstacleGrid = {
        {0,0,0},{0,1,0},{0,0,0}
    };

    int ans = solution.uniquePathsWithObstacles(obstacleGrid);
}