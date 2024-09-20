#include <iostream>
#include <vector>
using namespace std;

class Solution {
    int operate(int a, int b, char op) {
        if (op == '*') return a * b;
        else if (op == '+') return a + b;
        else return a - b;
    }
    vector<int> dp[20][20];
public:
    vector<int> solve(string& exp, int idx, int n) {
        if (idx == n) return {exp[idx] - '0'};
        if (idx == n-1) return {(exp[idx] - '0') * 10 + (exp[idx+1] - '0')};

        if (!dp[idx][n].empty()) return dp[idx][n];

        vector<int> ans;

        for (int i=idx; i<n; i++) {
            if (!isdigit(exp[i])) {
                vector<int> left = solve(exp, idx, i-1);
                vector<int> right = solve(exp, i+1, n);

                for (auto a : left) {
                    for (auto b : right) {
                        ans.push_back(operate(a, b, exp[i]));
                    }
                }
            }
        }

        dp[idx][n] = ans;

        return ans;
    }

    vector<int> diffWaysToCompute(string expression) {
        return solve(expression, 0, expression.size()-1);
    }
};

int main() {
    string exp = "2*3-4*5";
    Solution solution;
    
    vector<int> ans = solution.diffWaysToCompute(exp);

    return 0;
}