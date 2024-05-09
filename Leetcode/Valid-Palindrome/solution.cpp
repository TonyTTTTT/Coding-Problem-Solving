#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if (s == "") return true;

        int l=0, r=s.size()-1;

        while (l<r) {
            if (!isalnum(s[l])) {
                l++;
            } else if (!isalnum(s[r])) {
                r--;
            } else {
                if (tolower(s[l]) != tolower(s[r])) return false;

                l++;r--;
            }

        }

        return true;
    }
};

int main() {
    Solution solution;
    string s = "A man, a plan,c a canal: Panama";

    bool ans = solution.isPalindrome(s);
    __asm("nop");
}