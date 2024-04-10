#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    set<string> s;

    int doOperation(string op) {
        int optr_idx = 0;
        if (!isdigit(op[optr_idx])) {
            optr_idx++;
        }
        while(isdigit(op[optr_idx])) {
            optr_idx++;
        }

        int a = stoi(op.substr(0, optr_idx));
        if (optr_idx >= op.length()) {
            return a;
        }
        int b = stoi(op.substr(optr_idx+1));
        char opter = op[optr_idx];

        switch (opter) {
            case '+':
                return a+b;
            case '-':
                return a-b;
            default: //'*'
                return a*b;
        }
    }

    int findOpEnd(string expression) {
        int i = 0;
        if (!isdigit(expression[i])) {
            i++;
        }

        while (isdigit(expression[i])) {
            i++;
        }
        i++;

        if (!isdigit(expression[i])) {
            i++;
        }

        while (isdigit(expression[i])) {
            i++;
        }
        
        return i > expression.length() ? expression.length() : i;
    }

    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;
        int current_idx = 0;
        int op_len;
        int op_result;

        if (findOpEnd(expression) == expression.length()) {
            if (s.find(expression) == s.end()) {
                ans.push_back(doOperation(expression));
                s.insert(expression);
            }
            return ans;
        }

        while (current_idx+2 < expression.length()) {
            if ((!isdigit(expression[current_idx]) && current_idx+3 >= expression.length())) { break; }

            op_len = findOpEnd(expression.substr(current_idx));
            op_result = doOperation(expression.substr(current_idx, current_idx+op_len));
            string replaced_expression = expression;
            replaced_expression.replace(current_idx, op_len, to_string(op_result));

            vector<int> sub_ans = diffWaysToCompute(replaced_expression);
            ans.insert(ans.end(), sub_ans.begin(), sub_ans.end());

            if (!isdigit(expression[current_idx])) {
                current_idx++;
            }
            while(isdigit(expression[current_idx])) {
                current_idx++;
            }
            current_idx++;
        }

        return ans;
    }
};

int main() {
    string exp = "0";
    Solution solution;
    
    vector<int> ans = solution.diffWaysToCompute(exp);
    __asm("nop");
}