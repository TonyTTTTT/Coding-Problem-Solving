#include <iostream>
#include <vector>
using namespace std;

// class Solution {
// public:
// //     // int minDistance(string word1, string word2) {
// //     //     vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1));
// //     //     vector<bool> t(word2.size()+1, 0);

// //     //     dp[0][0] = 0;
// //     //     for (int i=1; i<=word1.size(); i++) dp[i][0] = i-1;
// //     //     for (int j=1; j<=word2.size(); j++) dp[0][j] = j-1;

// //     //     for (int i=1; i<=word1.size(); i++) {
// //     //         for (int j=1; j<=word2.size(); j++) {
// //     //             int a = dp[i-1][j];
// //     //             if (t[j]) a++;
// //     //             if (word1[i-1] == word2[j-1]) {
// //     //                 dp[i][j] = min(a, dp[i-1][j-1]);
// //     //                 if (dp[i][j] == dp[i-1][j-1]) t[j] = true;
// //     //             } else { // word1[i-1] != word2[j-1]
// //     //                 dp[i][j] = min(dp[i][j-1]+1, a);
// //     //             }
// //     //         }
// //     //     }

// //     //     return dp[word1.size()][word2.size()];
// //     // }
// //     // int recursive(string& word1, string& word2, int n1, int n2) {
// //     //     if (n1 == 0) return n2;
// //     //     if (n2 == 0) return n1;
        
// //     //     int ans = min(recursive(word1, word2, n1-1, n2)+1, recursive(word1, word2, n1, n2-1)+1);

// //     //     if (word1[n1-1] == word2[n2-1]) ans = min(recursive(word1, word2, n1-1, n2-1), ans);

// //     //     return ans;
// //     // }

// //     // int minDistance(string word1, string word2) {
// //     //     return recursive(word1, word2, word1.size(), word2.size());
// //     // }

// //     vector<vector<pair<int, int>>> findValidPairs(vector<pair<int, int>>& pairs, int curPairIdx, int idx1, int idx2, vector<vector<vector<pair<int, int>>>>& mem){
// //         if (curPairIdx == pairs.size()-1) {
// //             if (pairs[curPairIdx].first > idx1 && pairs[curPairIdx].second > idx2) return {{pairs[curPairIdx]}};
// //             else return {{}};
// //         }

        
// //         vector<vector<pair<int, int>>> res;
// //         if (pairs[curPairIdx].first > idx1 && pairs[curPairIdx].second > idx2) {
// //             if (mem[curPairIdx].empty()) {
// //                 mem[curPairIdx] = findValidPairs(pairs, curPairIdx+1, pairs[curPairIdx].first, pairs[curPairIdx].second, mem);
        
// //                 for (int i=0; i<mem[curPairIdx].size(); i++) {
// //                     mem[curPairIdx][i].push_back(pairs[curPairIdx]);
// //                 }   
// //             }

// //             res = mem[curPairIdx];
// //         }

// //         vector<vector<pair<int, int>>> noCur = findValidPairs(pairs, curPairIdx+1, idx1, idx2, mem);
// //         res.insert(res.end(), noCur.begin(), noCur.end());

// //         return res;
// //     }

//     int minDistance(string word1, string word2) {
//         if (word1.empty() || word2.empty()) return max(word1.size(), word2.size());

//         vector<pair<int, int>> pairs;

//         for (int i=0; i<word1.size(); i++) {
//             for (int j=0; j<word2.size(); j++) {
//                 if (word1[i] == word2[j]) pairs.push_back({i, j});
//             }
//         }

//         if (pairs.empty()) return max(word1.size(), word2.size());

//         vector<vector<vector<int>>> dp(pairs.size());
//         for (int i=0; i<pairs.size(); i++) {
//             dp[0].push_back({i});
//         }

//         for (int i=1; i<pairs.size(); i++) {
//             for (int j=0; j<dp[i-1].size(); j++) {
//                 int lastPairIdx = dp[i-1][j][dp[i-1][j].size()-1];
//                 for (int k=lastPairIdx+1; k<dp[0].size(); k++) {
//                     if (pairs[k].first > pairs[lastPairIdx].first && pairs[k].second > pairs[lastPairIdx].second) {
//                         dp[i].push_back(dp[i-1][j]);
//                         dp[i][dp[i].size()-1].push_back(k);
//                     }
//                 }
//             }
//             if (dp[i].size() == 0) break;
//         }

//         int ans = INT_MAX;
//         int curDis;
//         int PairNumAns = INT_MAX;
//         for (int i=dp.size()-1; i>=0; i--) {
//             PairNumAns = INT_MAX;
//             for (int j=0; j<dp[i].size(); j++) {
//                 curDis = max(pairs[dp[i][j][0]].first, pairs[dp[i][j][0]].second);
//                 int pIdx=0;
//                 int pIdxLast=0;
//                 for (int k=1; k<dp[i][j].size(); k++) {
//                     pIdx = dp[i][j][k];
//                     pIdxLast = dp[i][j][k-1];
//                     curDis += max(pairs[pIdx].first-pairs[pIdxLast].first-1, pairs[pIdx].second-pairs[pIdxLast].second-1);
//                 }
//                 curDis += max(word1.size()-1-pairs[pIdx].first, word2.size()-1-pairs[pIdx].second);
//                 if (curDis < PairNumAns) PairNumAns = curDis;
//             }
//             if (PairNumAns <= ans) ans = PairNumAns;
//             else break;
//         }

//         return ans;
//     }
// };

class Solution {
public:
    void findValidPairs(vector<pair<int, int>>& pairs, int curPairIdx, int idx1, int idx2, vector<vector<pair<int, int>>>& validPairs, vector<pair<int, int>>& curPath, int& curLCSLen){
        if (curPairIdx >= pairs.size()) {
            if (curPath.size() > 0 && (validPairs.size()==0 || curPath.size() >= curLCSLen-1))
                validPairs.push_back(curPath);
            
            if (curPath.size() > curLCSLen) curLCSLen = curPath.size();
            return;
        }

        if (pairs[curPairIdx].first > idx1 && pairs[curPairIdx].second > idx2) {
            curPath.push_back(pairs[curPairIdx]);
            findValidPairs(pairs, curPairIdx+1, pairs[curPairIdx].first, pairs[curPairIdx].second, validPairs, curPath, curLCSLen);
            curPath.pop_back();
        }
        findValidPairs(pairs, curPairIdx+1, idx1, idx2, validPairs, curPath, curLCSLen);
    }

    int minDistance(string word1, string word2) {
        if (word1.empty() || word2.empty()) return max(word1.size(), word2.size());

        vector<pair<int, int>> pairs;

        for (int i=0; i<word1.size(); i++) {
            for (int j=0; j<word2.size(); j++) {
                if (word1[i] == word2[j]) pairs.push_back({i, j});
            }
        }

        vector<vector<pair<int, int>>> validPairs;
        vector<pair<int, int>> curPath;
        int curLCSLen = 0;

        findValidPairs(pairs, 0, -1, -1, validPairs, curPath, curLCSLen);

        if (validPairs.empty()) return max(word1.size(), word2.size());

        int LCSLen = validPairs[validPairs.size()-1].size();
        int ans = INT_MAX;
        int curDis;

        for (int i=validPairs.size()-1; i>=0; i--) {
            int pathLen = validPairs[i].size();
            if (pathLen < LCSLen-1) break;
            curDis = max(validPairs[i][0].first, validPairs[i][0].second);
            for (int j=1; j<pathLen; j++) {
                curDis += max(validPairs[i][j].first-validPairs[i][j-1].first-1, validPairs[i][j].second-validPairs[i][j-1].second-1);
            }
            curDis += max(word1.size()-1-validPairs[i][pathLen-1].first, word2.size()-1-validPairs[i][pathLen-1].second);

            if (curDis < ans) ans = curDis;
        }


        return ans;
    }
};

int main() {
    Solution solution;
    string word1 = "pneumonoultramicroscopicsilicovolcanoconiosis";
    string word2 = "ultramicroscopical";

    int ans = solution.minDistance(word1, word2);

    __asm("nop");
}