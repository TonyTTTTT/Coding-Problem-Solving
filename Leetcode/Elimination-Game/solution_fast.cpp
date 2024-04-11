#include <iostream>
#include <bitset>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    char findKthBit(vector<int> sizeVec, int k, int invertTime) {
        if (k == 1) {
            if (invertTime%2 == 0) return '0';
            else return '1';
        }

        char ans;

        for (int i=0; i<sizeVec.size(); i++) {
            if (k == (sizeVec[i]/2)+1) {
                if (invertTime%2 == 0) return '1';
                else return '0';
            } else if (sizeVec[i] >= k) {
                ans = findKthBit(sizeVec, sizeVec[i] - k + 1, invertTime+1);
                break;
            }
        }

        return ans;
    }

    char findKthBit(int n, int k) {
        if (k == 1) return '0';

        vector<int> sizeVec;
        sizeVec.push_back(1);
        
        for (int i=1; i<n; i++) {
            sizeVec.push_back(sizeVec[i-1] * 2 + 1);
        }

        char ans = findKthBit(sizeVec, k, 0);
        return ans;
    }
};

int main() {
    Solution solution;
    int n = 4;
    int k = 12;

    char ans = solution.findKthBit(n, k);
    __asm("nop");
}