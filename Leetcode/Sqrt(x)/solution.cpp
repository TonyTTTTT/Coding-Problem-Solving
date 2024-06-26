#include <math.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x==0) return 0;
         
        int l=0, r=x;
        int mid;

        while (l <= r) {
            mid = (l + r) / 2;
            

            if (mid > x/mid) {
                r = mid - 1;
            } else {
                if (mid+1 > x/(mid+1)) return mid;
                l = mid + 1;
            }
        }

        return mid;
    }
};

int main() {
    Solution solution;
    int x = 8;

    int ans = solution.mySqrt(x);
    
    __asm("nop");
}