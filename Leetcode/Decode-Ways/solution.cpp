#include <iostream>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;

        int n = s.size();
        int llast, last, cur;
        llast = last = cur = 1;

        for (int i=1; i<n; i++) {
            cur = 0;
            if (s[i] != '0') cur += last;
            if (s[i-1]=='1' || s[i-1]=='2' && s[i]<='6') cur += llast;
            if (cur == 0) break;

            llast = last;
            last = cur;
        }

        return cur;
    }
};

int main() {
    Solution solution;
    string s = "226";
    int ans = solution.numDecodings(s);

    return 0;
}