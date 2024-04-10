#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        set<string> ans_set_old = {""};
        set<string> ans_set_new;
        set<string>::iterator itr;
        vector<string> ans;
        string current, tmp;

        for (int i=0; i<n; i++) {
            ans_set_new.clear();
            for (itr=ans_set_old.begin(); itr!=ans_set_old.end(); itr++) {
                current =  *itr;

                for (int j=0; j<current.size(); j++) {
                    tmp = current;
                    tmp.insert(j, "()");
                    ans_set_new.insert(tmp);
                }

                if (current.size() == 0) {
                    ans_set_new.insert("()");
                }
            }
            ans_set_old = ans_set_new;
        }

        for (itr=ans_set_new.begin(); itr!=ans_set_new.end(); itr++) {
            ans.push_back(*itr);
        }

        return ans;
    }
};

int main() {
    Solution solution;

    vector<string> ans = solution.generateParenthesis(2);

    return 0;
}