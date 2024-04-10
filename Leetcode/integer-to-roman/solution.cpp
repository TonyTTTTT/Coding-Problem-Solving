#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    void append_string(int digit, string &ans, string one, string five, string ten) {
        if (digit < 4) {
            for (int i=0; i<digit; i++) {
                ans.append(one);
            }
        } else if (digit == 4) {
            ans.append(one+five);
        } else if (digit >= 5 and digit < 9) {
            ans.append(five);
            digit = digit % 5;
            for (int i=0; i<digit; i++) {
                ans.append(one);
            }
        } else if (digit == 9) {
            ans.append(one+ten);
        } else {
            printf("error\n");
        }
    }

    string intToRoman(int num) {
        string ans = "";
        int digits[4] = {0, 0, 0, 0};
        int idx = 3;

        while (num > 0) {
            digits[idx] = num % 10;
            num /= 10;
            idx--;
        }
        
        this->append_string(digits[0],  ans, "M", "|", "|");
        this->append_string(digits[1], ans, "C", "D", "M");
        this->append_string(digits[2], ans, "X", "L", "C");
        this->append_string(digits[3], ans, "I", "V", "X");

        return ans;
    }
};

int main() {
    Solution solution;

    string ans = solution.intToRoman(2999);
    cout<<ans<<endl;
    return 0;
}