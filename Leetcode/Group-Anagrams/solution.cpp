#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        vector<vector<string>> ans;

        for (int i=0; i<strs.size(); i++) {
            string sorted = strs[i];
            sort(sorted.begin(), sorted.end());
            unordered_map<string, vector<string>>::iterator iter = m.find(sorted);
            if (iter != m.end()) {
                iter->second.push_back(strs[i]);
            } else {
                m.insert(pair<string, vector<string>>(sorted, {strs[i]}));
            }
        }

        for (unordered_map<string, vector<string>>::iterator iter=m.begin(); iter!=m.end(); iter++) {
            ans.push_back(iter->second);
        }

        return ans;
    }
};

int main() {
    Solution solution;
    vector<string> strs{"eat","tea","tan","ate","nat","bat"};

    vector<vector<string>> ans = solution.groupAnagrams(strs);
}