#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;
        vector<int> cnt(26, 0);
        int l, r, maxCnt;
        l = r = maxCnt = 0;

        while (r < s.size()) {
            maxCnt = max(maxCnt, ++cnt[s[r] - 'A']);
            while (r - l + 1 - maxCnt > k) {
                cnt[s[l] - 'A']--;
                l++;
                maxCnt = 0;
                for (int i=0; i<26; i++) maxCnt = max(maxCnt, cnt[i]);
            }
            ans = max(ans, r - l + 1);
            r++;
        }
        

        return ans;
    }
};

int main() {
    Solution soluion;
    string s = "AABABBA";
    int k = 1;

    int ans = soluion.characterReplacement(s, k);
}