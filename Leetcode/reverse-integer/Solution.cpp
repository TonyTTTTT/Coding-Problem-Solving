#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        int pop;
        bool positive;
        if (x >= 0) {
            while (x!=0) {
                pop = x%10;
                if (ans > ((INT32_MAX - pop)/10)) {
                    return 0;
                }
                ans *= 10;
                ans += pop;
                x /= 10;
            }
        } else { // x < 0
            while (x!=0) {
                pop = x%10;
                if (ans < ((INT32_MIN - pop)/10)) {
                    return 0;
                }
                ans *= 10;
                ans += x%10;
                x /= 10;
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;
    int ans = solution.reverse(2147483647);
    cout<<"ans: "<<ans<<endl;
    return 0;
}