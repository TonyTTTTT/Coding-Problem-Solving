#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    bool isMatch(string s, string p) {
        bool dp[21][31] = {false};
        dp [s.size()][p.size()] = true;

        for (int i=s.size(); i>=0; i--) {
            for (int j=p.size()-1; j>=0; j--) {
                bool first_match = (i < s.size()) and (s[i] == p[j] or p[j] == '.');

                if (j+1 < p.size() and p[j+1] == '*') {
                    dp[i][j] = dp[i][j+2] or (first_match and dp[i+1][j]);
                } else {
                    dp[i][j] = first_match and dp[i+1][j+1];
                }
            }
        }
        
        return dp[0][0];
    }
};


int main() {
    Solution solution;
    bool ans = solution.isMatch("aa", "a*");
    if (ans) {
        cout<<"match"<<endl;
    } else {
        cout<<"not match"<<endl;
    }

    return 0;
}