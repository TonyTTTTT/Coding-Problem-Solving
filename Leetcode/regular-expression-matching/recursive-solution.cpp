#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        bool firstMatch = false;

        if (p.size() == 0) {
            if (s.size() == 0) {
                return true;
            } else {
                return false;
            }
        }

        if (s.size() > 0 and (s[0] == p[0] or p[0] == '.')) {
            firstMatch = true;
        }
        
        if (p.size() >= 2 and p[1] == '*') {
            return (isMatch(s, p.substr(2))) or (firstMatch and isMatch(s.substr(1), p));
        } else {
            return firstMatch and isMatch(s.substr(1), p.substr(1));
        }
      }
};

int main () {
    Solution solution;
    bool ans = solution.isMatch("ab", ".*c");

    if (ans) {
        cout<<"match"<<endl;
    } else {
        cout<<"not match"<<endl;
    }
    
    // string s = "";
    // cout<<s.substr(1, 2)<<endl;
    return 0;
}