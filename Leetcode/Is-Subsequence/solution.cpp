#include <iostream>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int p = 0;
        
        for (char c : t) {
            if (c == s[p]) p++;
            if (p == s.size()) break;
        }

        return p == s.size();
    }
};

int main() {
    Solution solution;
    string s = "abc";
    string t = "ahbgdc";

    bool ans = solution.isSubsequence(s, t);
}