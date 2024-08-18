#include <string>
using namespace std;

class Solution {
    void expand(string& s, int l, int r, int& ans) {
        while(l>=0 && r<s.size() && s[l]==s[r]) {
            ans++;
            l--;r++;
        }
    }
public:
    int countSubstrings(string s) {
        int ans = s.size();
        int n = s.size();

        for (int i=0; i<n; i++) {
            expand(s, i-1, i+1, ans);
            expand(s, i, i+1, ans);
        }

        return ans;
    }
};

int main() {
    Solution solution;
    string s = "aba";

    int ans = solution.countSubstrings(s);
}