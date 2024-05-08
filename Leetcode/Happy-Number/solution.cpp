#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    int nextNum(int n) {
        int res = 0;
        while (n!=0) {
            res += (n%10) * (n%10);
            n /= 10;
        }

        return res;
    }
    
    bool isHappy(int n) {
        int slow=n, fast=n;

        while (fast != 1) {
            slow = nextNum(slow);
            fast = nextNum(fast);
            fast = nextNum(fast);

            if (slow == fast && slow != 1) return false;
        }

        return true;
    }
};

int main() {
    Solution solution;
    int n = 10;

    bool ans = solution.isHappy(n);
    __asm("nop");
}