#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int t1[256] = {0}, t2[256] = {0};


        for (int i=0; i<s.size(); i++) {
            if (t1[s[i]] != t2[t[i]]) return false;

            t1[s[i]] = i+1;
            t2[t[i]] = i+1;
        }

        return true;
    }
};

int main() {
    Solution solution;
    string s = "ab", t = "aa";

    bool ans = solution.isIsomorphic(s, t);
    __asm("nop");
}