#include <iostream>
#include <map>
#include <stdlib.h> 
using namespace std;

class Solution {
public:
    double Pow(double x, long long n) {
        if (n==0) return 1;

        if (n%2 == 0) {
            double half = myPow(x, n/2);
            return half * half;
        }

        return x * myPow(x, n-1);    
    }

    double myPow(double x, int n) {
        long long nl = n;
        if (nl<0) {
            x = 1/x;
            nl = -1 * nl;
        }

        return Pow(x, nl);
    }
};

int main() {
    Solution solution;
    double x = 2.00000;
    int n = -2147483648;

    double ans = solution.myPow(x, n);
    __asm("nop");
}