#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits == "") {
            return vector<string> {};
        }
        char now = digits[0];
        int now_int = now - 48;

        vector<string> tmp = letterCombinations(digits.erase(0, 1));
        if (tmp.empty()) {
            tmp.push_back("");
        }

        int mapping_length = 3;
        if (now_int == 7 or now_int == 9) {
            mapping_length = 4;
        }
        int base = 97+3*(now_int-2);
        if (now_int == 8 or now_int == 9) {
            base ++;
        }

        vector<char> mapping;
        for (int i=base; i<base+mapping_length; i++) {
            mapping.push_back(i);
        }

        vector<string> ans;
        for(int i=0; i<mapping.size(); i++) {
            for (int j=0; j<tmp.size(); j++) {
                string combined = tmp[j];
                combined.insert(0, 1, mapping[i]);
                ans.push_back(combined);
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;
    // '0' == 48
    // 'a' == 97
    vector<string> ans = solution.letterCombinations("23");
    return 0;
}