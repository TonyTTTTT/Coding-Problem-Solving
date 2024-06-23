#include <iostream>
#include <unordered_map>
#include <sstream>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, int> p2i;
        unordered_map<string, int> w2i;
        istringstream iss(s);

        int i=0;
        for (string word; iss>>word; i++) {
            if (i == pattern.size() ||p2i[pattern[i]] != w2i[word]) return false;
            p2i[pattern[i]] = w2i[word] = i+1;
        }

        return i == pattern.size();
    }
};

int main() {
    Solution solution;
    string pattern = "abba";
    string s = "dog cat cat dog";

    bool ans = solution.wordPattern(pattern, s);
}