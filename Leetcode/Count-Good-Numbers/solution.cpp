#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    long long power(long long b, long long e) {
        if (e==0) return 1;

        long long result;

        if (e%2 == 0) {
            result = power(b, e/2) % 1000000007;
            return (result * result) % 1000000007;
        } else {
            result = power(b, e-1) % 1000000007;
            return (result * b) % 1000000007;
        }
    }

    int countGoodNumbers(long long n) {
        long long ans;
        if (n%2 == 0) {
            ans = power(5, n/2) * power(4, n/2);
        } else {
            ans = power(5, n/2 + 1) * power(4, n/2);
        }
        ans %= 1000000007;

        return ans;
    }
};

int main() {
    Solution solution;
    int n = 50;
    int ans = solution.countGoodNumbers(n);

    return 0;
}