#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int i, j, loop_cnt;
        string ans;

        ans.clear();
        if (numRows == 1) {
            return s;
        }
        else {
            j = 0;
            while (j<s.size()) {
                ans.push_back(s[j]);
                j += (numRows-1) * 2;
            }
            for (i=1; i<numRows-1; i++) {
                j = i;
                loop_cnt = 0;
                while (j<s.size()) {
                    ans.push_back(s[j]);
                    if (loop_cnt % 2 == 0) {
                        j += (numRows-1)*2 - 2*i;
                    } else { //loop_cnt % 2 == 1
                        j += 2*i;
                    }
                    loop_cnt++;
                }
            }
            j = numRows-1;
            while (j<s.size()) {
                ans.push_back(s[j]);
                j += (numRows-1) * 2;
            }
            return ans;
        }
    }
};

int main() {
    Solution solution;
    string ans = solution.convert("A", 1);
    cout<<"ans: "<<ans<<endl;
    return 0;
}