#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string ans = "";
        int idx = 0;

        while (true) {
            for (int i=0; i<strs.size(); i++) {
                if (idx >= strs[i].size() || (i!=0 && strs[i][idx]!=strs[i-1][idx])) return ans;
            }
            ans += strs[0][idx];
            idx++;
        }

        return ans;
    }
};

int main() {
    Solution solution;
    vector<string> strs = {"dog","racecar","carr"};

    string ans = solution.longestCommonPrefix(strs);

    __asm("nop");
}