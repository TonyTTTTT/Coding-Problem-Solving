#include <iostream>
#include <bitset>
#include <algorithm>
using namespace std;

class Solution {
public:
    string invertAndReverse(string s) {
        for (int i=0; i<s.size(); i++) {
            if (s[i] == '0') s[i] = '1';
            else s[i] = '0';
        }
        reverse(s.begin(), s.end());

        return s;
    }

    char findKthBit(int k, string s) {
        string tmp = "1" + invertAndReverse(s);

        if (k < tmp.size()) {
            return tmp[k];
        }

        s = s + tmp;

        char ans = findKthBit(k-tmp.size(), s);

        return ans;
    }

    char findKthBit(int n, int k) {
        if (k==1) return '0';

        string s = "0";

        char ans = findKthBit(k-2, s); 

        return ans;
    }
};

int main() {
    Solution solution;
    int n = 8;
    int k = 158;

    char ans = solution.findKthBit(n, k);
    __asm("nop");
}