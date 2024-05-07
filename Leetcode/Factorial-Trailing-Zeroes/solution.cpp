#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int fiveCnt = 0;

        for (int i=5; i<=n; i*=5) {
            fiveCnt += n/i;
        }
        

        return fiveCnt;
    }
};

int main() {
    Solution solution;
    int n = 10000;

    int ans = solution.trailingZeroes(n);
}