#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp;
        dp.push_back(true);
        
        
        for (int i=1; i<=s.size(); i++) {
            bool isWordBreak;
            for (int j=i-1; j>=0; j--) {
                isWordBreak = dp[j] && find(wordDict.begin(), wordDict.end(), s.substr(j, i-j)) != wordDict.end();

                if (isWordBreak) break;
            }
            dp.push_back(isWordBreak);
        }

        return dp[s.size()];
    }
};

int main() {
    Solution solution;
    string s = "catsandog";
    vector<string> wordDict = {"cats","dog","sand","and","cat"};

    bool ans = solution.wordBreak(s, wordDict);
}