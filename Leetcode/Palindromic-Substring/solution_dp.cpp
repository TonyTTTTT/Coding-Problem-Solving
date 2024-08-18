#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int ans = s.size();
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n));
        for (int i=0; i<n; i++) dp[i][i] = true;
        for (int i=0; i<n-1; i++) {
            if (s[i] == s[i+1]) {
                dp[i][i+1] = true;
                ans++;
            }
        }

        for (int offset=2; offset<n; offset++) {
            for (int i=0; i+offset<n; i++) {
                if (s[i] == s[i+offset] && dp[i+1][i+offset-1]) {
                    ans++;
                    dp[i][i+offset] = true;
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;
    string s = "aaaaaa";

    int ans = solution.countSubstrings(s);
}