#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<vector<char>> t = {
            {'I', 'V', 'X'},
            {'X', 'L', 'C'},
            {'C', 'D', 'M'},
            {'M'}
        };
        int digitPlace = -1;
        int curr;
        string ans = "";

        while (num != 0) {
            digitPlace++;
            curr = num%10;
            num /= 10;

            if (curr == 0) continue;
            else if (curr == 4) {
                ans += t[digitPlace][1];
                ans += t[digitPlace][0];
                continue;
            } else if (curr == 9) {
                ans += t[digitPlace][2];
                ans += t[digitPlace][0];
                continue;
            }

            while(curr > 5) {
                ans += t[digitPlace][0];
                curr--;
            }
            if (curr == 5) {
                ans += t[digitPlace][1];
                continue;
            }

            while (curr > 0) {
                ans += t[digitPlace][0];
                curr--;
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main() {
    Solution solution;
    int num = 3999;

    string ans = solution.intToRoman(num);
}