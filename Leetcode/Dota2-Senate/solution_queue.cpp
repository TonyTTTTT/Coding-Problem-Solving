#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        int rCnt = 0;
        int dCnt = 0;
        queue<char> q;

        for (auto c : senate) {
            q.push(c);
            if (c == 'R') rCnt++;
            else dCnt++;
        }

        int rBaned = 0;
        int dBaned = 0;

        while (rCnt && dCnt) {
            char f = q.front();
            q.pop();

            if (f == 'R') {
                if (rBaned == 0) {
                    q.push(f);
                    dBaned++;
                    dCnt--;
                } else {
                    rBaned--;
                }
            } else {
                if (dBaned == 0) {
                    q.push(f);
                    rBaned++;
                    rCnt--;
                } else {
                    dBaned--;
                }
            }
        }
        
        return rCnt == 0 ? "Dire" : "Radiant";
    }
};

int main() {
    Solution sol;
    string senate = "RDD";

    string ans = sol.predictPartyVictory(senate);

    return 0;
}