#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> m;
        string s = s1 + " " + s2;
        stringstream ss(s);
        string word;

        while (ss >> word) m[word]++;

        vector<string> ans;
        for (auto itr : m) {
            if (itr.second == 1) ans.push_back(itr.first);
        }

        return ans;
    }
};

int main() {
    string s1 = "this apple is sweet";
    string s2 = "this apple is sour";
    Solution sol;

    vector<string> ans = sol.uncommonFromSentences(s1, s2);

    return 0;
}