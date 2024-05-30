#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isInterleave(string& s1, string& s2, string& s3, vector<vector<int>>& mem, int i, int j) {
        if (i == s1.size()) {
            mem[i][j] = s2.substr(0, s2.size()-j) == s3.substr(0, s3.size()-i-j);
            return mem[i][j];
        } else if (j == s2.size())  {
            mem[i][j] = s1.substr(0, s1.size()-i) == s3.substr(0, s3.size()-i-j);
            return mem[i][j];
        } else if (i+j == s3.size()) {
            mem[i][j] = false;
            return mem[i][j];
        }

        bool ans1 = false;
        if (s1[s1.size()-1-i] == s3[s3.size()-1-i-j]) {
            if (mem[i+1][j] == -1) {
                mem[i+1][j] = isInterleave(s1, s2, s3, mem, i+1, j);
            }
            ans1 = mem[i+1][j];
        }

        bool ans2 = false;
        if (s2[s2.size()-1-j] == s3[s3.size()-1-i-j]) {
            if (mem[i][j+1] == -1) {
                mem[i][j+1] = isInterleave(s1, s2, s3, mem, i, j+1);
            }
            ans2 = mem[i][j+1];
        }

        mem[i][j] = ans1 || ans2;

        return mem[i][j];
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;

        int m = s1.size();
        int n = s2.size();

        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        dp[0][0] = 1;



        for (int j=1; j<n+1; j++) {
            dp[0][j] = (s2[j-1] == s3[j-1]) && dp[0][j-1];
        }

        for (int i=1; i<m+1; i++) {
            dp[i][0] = (s1[i-1] == s3[i-1]) && dp[i-1][0];
        }

        for (int i=1; i<m+1; i++) {
            for (int j=1; j<n+1; j++) {
                dp[i][j] = ((s1[i-1] == s3[i+j-1]) && dp[i-1][j]) ||
                            ((s2[j-1] == s3[i+j-1]) && dp[i][j-1]);
            }
        }


        return dp[m][n];
    }
};

int main() {
    Solution solution;
    string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";

    bool ans = solution.isInterleave(s1, s2, s3);

    __asm("nop");
}