#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<pair<string, int>> q;
        vector<string> seen;

        q.push({startGene, 0});

        while (!q.empty()) {
            string current = q.front().first;
            int cnt = q.front().second;
            q.pop();
            for (int i=0; i<bank.size(); i++) {
                int distance = 0;

                for (int j=0; j<bank[i].size(); j++) {
                    if (bank[i][j] != current[j]) distance++;
                }

                if (distance == 1) {
                    if (bank[i] == endGene) {
                        return cnt+1;
                    } else if (find(seen.begin(), seen.end(), bank[i]) == seen.end()) {
                        seen.push_back(bank[i]);
                        q.push({bank[i], cnt+1});
                    }
                }
            }
        }

        return -1;
    }
};

int main() {
    string startGene = "AAAAAAAA";
    string endGene = "CCCCCCCC";
    vector<string> bank = {"AAAAAAAA","AAAAAAAC","AAAAAACC","AAAAACCC","AAAACCCC","AACACCCC","ACCACCCC","ACCCCCCC","CCCCCCCA"};
    Solution solution;

    int ans = solution.minMutation(startGene, endGene, bank);
    __asm("nop");
}