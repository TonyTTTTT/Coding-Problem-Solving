#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1));
        vector<bool> t(word2.size()+1, 0);

        dp[0][0] = 0;
        for (int i=1; i<=word1.size(); i++) dp[i][0] = i-1;
        for (int j=1; j<=word2.size(); j++) dp[0][j] = j-1;

        for (int i=1; i<=word1.size(); i++) {
            for (int j=1; j<=word2.size(); j++) {
                int a = dp[i-1][j];
                if (t[j]) a++;
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = min(a, dp[i-1][j-1]);
                    if (dp[i][j] == dp[i-1][j-1]) t[j] = true;
                } else { // word1[i-1] != word2[j-1]
                    dp[i][j] = min(dp[i][j-1]+1, a);
                }
            }
        }

        return dp[word1.size()][word2.size()];
    }
    // int recursive(string& word1, string& word2, int n1, int n2) {
    //     if (n1 == 0) return n2;
    //     if (n2 == 0) return n1;
        
    //     int ans = min(recursive(word1, word2, n1-1, n2)+1, recursive(word1, word2, n1, n2-1)+1);

    //     if (word1[n1-1] == word2[n2-1]) ans = min(recursive(word1, word2, n1-1, n2-1), ans);

    //     return ans;
    // }

    // int minDistance(string word1, string word2) {
    //     return recursive(word1, word2, word1.size(), word2.size());
    // }

};

int main() {
    Solution solution;
    string word1 = "intention";
    string word2 = "execution";

    int ans = solution.minDistance(word1, word2);

    __asm("nop");
}