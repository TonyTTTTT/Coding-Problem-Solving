#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int ans = INT_MAX;

        for (int i=0; i<n; i++) {
            if (words[(startIndex+i)%n] == target) {
                int possibleAns = min(i, n-i);
                ans = min(ans, possibleAns);
            }
        }

        if (ans == INT_MAX) ans = -1;
        
        return ans;
    }
};

int main() {
    Solution solution;

    vector<string> words = {"hello","i","am","leetcode","hello"};
    string target = "hello";
    int startIndex = 1;

    int ans = solution.closetTarget(words, target, startIndex);
}