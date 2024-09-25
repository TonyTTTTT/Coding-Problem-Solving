#include <iostream>
using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        int rCnt = 0;
        int dCnt = 0;

        for (auto c : senate) {
            if (c == 'R') rCnt++;
            else dCnt++;
        }

        auto itr = senate.begin();
        while (rCnt && dCnt) {
            auto tmpItr = itr;
            if (*itr == 'R') {
                while (*tmpItr == 'R') {
                    tmpItr++;
                    if (tmpItr == senate.end()) tmpItr = senate.begin();
                }
                if (tmpItr < itr) itr--;
                senate.erase(tmpItr);
                dCnt--;
            } else {
                while (*tmpItr == 'D') {
                    tmpItr++;
                    if (tmpItr == senate.end()) tmpItr = senate.begin();
                }
                if (tmpItr < itr) itr--;
                senate.erase(tmpItr);
                rCnt--;
            }
            itr++;
            if (itr == senate.end()) itr = senate.begin();
        }

        return senate.front() == 'R' ? "Radiant" : "Dire";
    }
};

int main() {
    Solution sol;
    string senate = "DDRRR";

    string ans = sol.predictPartyVictory(senate);

    return 0;
}