#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (magazine.size() < ransomNote.size()) return false;

        // unordered_map<char, int> map;
        vector<int> map(26, 0);

        for (auto c : magazine) {
            map[c-97]++;
        }

        for (auto c : ransomNote) {
            if (map[c-97] == 0) return false;
            map[c-97]--;
        }

        return true;
    }
};

int main() {
    Solution solution;
    string ransomNote = "caa";
    string magazine = "aab";

    bool ans = solution.canConstruct(ransomNote, magazine);
}