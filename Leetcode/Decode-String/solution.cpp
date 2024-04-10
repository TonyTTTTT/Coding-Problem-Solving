#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<char> stk;
        string tmp;
        string time;
        string ans = "";

        for (int i=0; i<s.size(); i++) {
            if (s[i] == ']') {
                tmp = "";
                while (stk.top() != '[') {
                    tmp.insert(0, 1, stk.top());
                    stk.pop();
                }
                stk.pop();

                time = "";
                while (isdigit(stk.top())) {
                    time.insert(0, 1, stk.top());
                    stk.pop();
                    if (stk.empty()) break;
                }

                tmp = expand(tmp, stoi(time));
                for (int j=0; j<tmp.size(); j++) {
                    stk.push(tmp[j]);
                }
            } else {
                stk.push(s[i]);
            }
        }

        while(!stk.empty()) {
            ans.insert(0, 1, stk.top());
            stk.pop();
        }

        return ans;
    }

    string expand(string s, int time) {
        string result = "";

        for (int i=0; i<time; i++) {
            result += s;
        }

        return result;
    }
};

int main() {
    Solution solution;
    string s = "2[abc]3[cd]ef";
    solution.decodeString(s);

    return 0;
}