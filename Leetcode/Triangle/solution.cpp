#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp = {10001, triangle[0][0], 10001};
        int m = triangle.size();

        for (int i=1; i<m; i++) {
            int last = 10001, current;
            for (int j=1; j<=triangle[i].size(); j++) {
                current = min(dp[j], dp[j-1]) + triangle[i][j-1];
                dp[j-1] = last;
                last = current;
            }
            dp[dp.size()-1] = current;
            dp.push_back(10001);
        }

        int ans = dp[1];

        for (int i=2; i<dp.size()-1; i++) {
            if (dp[i] < ans) ans = dp[i];
        }
        vector<int> minlen(triangle.back());
        return ans;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};

    int ans = solution.minimumTotal(triangle);
}