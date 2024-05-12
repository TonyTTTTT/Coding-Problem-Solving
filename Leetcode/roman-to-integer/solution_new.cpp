#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        int last = INT_MAX;
        int current;
        int n = s.size();

        for (int i=0; i<n; i++) {
            if (s[i] == 'I') current = 1;
            else if (s[i] == 'V') current = 5;
            else if (s[i] == 'X') current = 10;
            else if (s[i] == 'L') current = 50;
            else if (s[i] == 'C') current = 100;
            else if (s[i] == 'D') current = 500;
            else if (s[i] == 'M') current = 1000;

            ans += current;
            if (current > last) ans -= last * 2;

            last = current;
        }

        return ans;
    }
};

int main() {
    Solution solution;
    string s = "MCMXCIV";
    
    int ans = solution.romanToInt(s);
}