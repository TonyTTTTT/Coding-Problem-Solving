#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int start = s.size() - 1;
        
        while (start>=0 && s[start] == ' ') start--;

        if (start < 0) return 0;
        int end = start;

        while (start>=0 && s[start] != ' ') start--;

        return end - start;
    }
};

int main() {
    Solution solution;
    string s = "yerldsf";

    int ans = solution.lengthOfLastWord(s);
    __asm("nop");
}