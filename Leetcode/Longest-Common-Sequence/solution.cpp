#include <vector>
#include <iostream>
#include <stdlib.h>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(2, vector<int>(m+1, 0));
        int ans = 0;

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                dp[1][j+1] = max(dp[0][j] + (text1[i] == text2[j]), max(dp[1][j], dp[0][j+1]));

                ans = max(ans, dp[1][j+1]);
            }
            dp[0] = dp[1];
        }

        return ans;
    }
};

int main() {
    Solution solution;
    string text1 = "abcba";
    string text2 = "abcbcba";

    int ans = solution.longestCommonSubsequence(text1, text2);
}