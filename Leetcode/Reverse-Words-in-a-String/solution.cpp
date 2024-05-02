#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int current = s.size()-1;
        int wordLength;

        while (current >= 0) {         
            while (s[current] == ' ') {
                current--;
                if (current < 0) break;
            }
            if (current < 0) break;

            wordLength = 0;
            while (s[current] != ' ') {
                current--;
                wordLength++;
                if (current < 0) break;
            }

            ans += s.substr(current+1, wordLength);
            ans += " ";
        }
        ans = ans.substr(0, ans.size()-1);

        return ans;
    }
};

int main() {
    Solution solution;
    string s = "a";

    string ans = solution.reverseWords(s);
}