#include <vector>
#include <stdlib.h>
#include <map>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0) return 0;

        long long longN = n;
        longN = abs(longN);
        double ans = 1;

        while (longN > 0) {
            if (longN % 2) { // odd
                ans *= x;
                longN--;
            } else { // even
                x *= x;
                longN /= 2;
            }
        }

        if (n < 0) ans = 1 / ans;

        return ans;
    }
};

int main() {
    Solution solution;
    double x = 2.00000;
    int n = 9;

    double ans = solution.myPow(x, n);
    __asm("nop");
}