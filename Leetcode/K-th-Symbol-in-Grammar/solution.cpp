#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
    int kthGrammar(int n, double k, int isIntCount) {
        if (n == 1) {
            if (isIntCount%2 == 0) {
                return 0;
            } else {
                return 1;
            }
        }


        return kthGrammar(n-1, ceil(k/2), k/2 == ceil(k/2) ? isIntCount+1 : isIntCount);
    }

    int kthGrammar(int n, int k) {
        if (n==1) return 0;
        double kDouble = k;
        int isIntCount = 0;

        int ans = kthGrammar(n-1, ceil(kDouble/2), kDouble/2 == ceil(kDouble/2) ? isIntCount+1 : isIntCount);

        return ans;
    }
};

int main() {
    Solution solution;
    int n = 2;
    int k = 2;
    int ans = solution.kthGrammar(n, k);

    __asm("nop");
}