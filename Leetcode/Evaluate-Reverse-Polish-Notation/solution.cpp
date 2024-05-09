#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
#include <functional>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int a, b;

        for (auto token : tokens) {
            if (token == "+") {
                b = s.top(); s.pop();
                a = s.top(); s.pop();
                s.push(a + b);
            } else if (token == "-") {
                b = s.top(); s.pop();
                a = s.top(); s.pop();
                s.push(a - b);
            } else if (token == "*") {
                b = s.top(); s.pop();
                a = s.top(); s.pop();
                s.push(a * b);
            } else if (token == "/") {
                b = s.top(); s.pop();
                a = s.top(); s.pop();
                s.push(a / b);
            } else {
                s.push(stoi(token));
            }
        }
        return s.top();
    }
};

int main() {
    Solution solution;
    vector<string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};

    int ans = solution.evalRPN(tokens);
}