#include <iostream>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int ans = -1;
        int j, k;

        for (int i=0; i<haystack.size(); i++) {
            j = i;
            k = 0;

            while (haystack[j] == needle[k]) {
                j++;
                k++;
                if (j==haystack.size() || k==needle.size()) break;
            }
            
            if (k==needle.size()) {
                ans = i;
                break;
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;
    string h = "mississippi";
    string n = "issip";

    int ans = solution.strStr(h, n);
}