#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int doOperation(int a, int b, char op) {
        if (op == '+') return a+b;
        else if (op == '-') return a-b;
        else return a*b;
    }

    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;
        bool is_number = true;

        for (int i=0; i<expression.length(); i++) {
            if (!isdigit(expression[i])) {
                is_number = false;

                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i+1));

                for (int a : left) {
                    for (int b : right) {
                        ans.push_back(doOperation(a, b, expression[i]));
                    }
                }
            }
        }

        if (is_number) {
            ans.push_back(stoi(expression));
        }

        return ans;
    }
};

int main() {
    string exp = "2*3-4*5";
    Solution solution;
    
    vector<int> ans = solution.diffWaysToCompute(exp);
    __asm("nop");
}