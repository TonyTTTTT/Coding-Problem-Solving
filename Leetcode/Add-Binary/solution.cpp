#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int c = 0;
        int idx1 = a.size() - 1;
        int idx2 = b.size() - 1;
        int aCurrent, bCurrent;
        string ans;

        while (idx1>=0 || idx2>=0) {
            if (idx1>=0) {
                aCurrent = a[idx1--] - '0';
            } else { aCurrent = 0; }

            if (idx2>=0) {
                bCurrent = b[idx2--] - '0';    
            } else { bCurrent = 0; }
            
            int sum = (aCurrent ^ bCurrent) ^ c;
            c = (aCurrent & bCurrent) | (aCurrent & c) | (bCurrent & c);

            ans.push_back('0'+sum);
        } 

        if (c == 1) ans.push_back('1');

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main() {
    Solution solution;
    string a = "1010";
    string b = "101";

    string ans = solution.addBinary(a, b);
}