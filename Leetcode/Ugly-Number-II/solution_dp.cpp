#include <cstring>
#include <algorithm>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        int dp[n];
        memset(dp, -1, sizeof(dp));
        dp[0] = 1;

        int idx2, idx3, idx5;
        idx2 = idx3 = idx5 = 0;

        for (int i=1; i<n; i++) {
            dp[i] = min(dp[idx2]*2, min(dp[idx3]*3, dp[idx5]*5));
            if (dp[i] == dp[idx2]*2) idx2++;
            if (dp[i] == dp[idx3]*3) idx3++;
            if (dp[i] == dp[idx5]*5) idx5++;
        }

        return dp[n-1];
    }
};

int main() {
    Solution solution;
    int n = 10;

    int ans = solution.nthUglyNumber(n);
}