#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        for (auto c : s) {
            if (c==')' || c==']' || c=='}') {
                if (stk.empty()) return false;
                char last = stk.top(); stk.pop();

                if (last!=c-1 && last!=c-2) return false;
            } else {
                stk.push(c);
            }
        }

        return stk.empty();
    }
};

int main() {
    Solution solution;
    string s = ")";

    bool ans = solution.isValid(s);
    __asm("nop");
}