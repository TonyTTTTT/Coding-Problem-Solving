#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        char current;
        for (int i=0; i<strs[0].size(); i++){
            current = strs[0][i];
            for (int j=1; j<strs.size(); j++) {
                if (strs[j][i] != current) {
                    return ans;
                }
            }
            ans.push_back(current);
        }
        return ans;
    }
};

int main () {
    Solution solution;
    vector<string> strs = {"dog","racecar","car"};
    string ans = solution.longestCommonPrefix(strs);
    cout<<ans<<endl;
    return 0;
}