#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> stk;
        int idx = 0;

        while (idx != path.size()) {
            int len = 0;

            while (path[idx+len] != '/' && idx+len != path.size()) {
                len++;
            }

            len = max(1, len);

            string current = path.substr(idx, len);
            
            if (current == "..") {
                if (stk.size() > 1) {
                    stk.pop();stk.pop();
                }
            } else if (current == "/"){
                if (stk.empty() || stk.top() != "/") stk.push(current);
            } else if (current != ".") {
                stk.push(current);
            }

            idx += len;
        }
        
        if (stk.top() == "/" && stk.size() > 1) stk.pop();

        stack<string> stk2;
        while (!stk.empty()) {
            stk2.push(stk.top());
            stk.pop();
        }

        string ans = "";

        while (!stk2.empty()) {
            ans += stk2.top();
            stk2.pop();
        }

        return ans;
    }
};

int main() {
    Solution solution;
    string path = "/../";

    string ans = solution.simplifyPath(path);
}