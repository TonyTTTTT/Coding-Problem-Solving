#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        if (piles.size() == 1) return ceil((double)piles[0] / h);

        int l = 1;
        int r = *max_element(piles.begin(), piles.end());

        while (l < r) {
            long long mid = (l + r) / 2;
            unsigned int need = 0;
            for (int pile : piles) need += ceil((double)pile / mid);

            if (need <= h) r = mid;
            else if (need > h) l = mid + 1;
        }

        return l;
    }
};

int main() {
    Solution sol;
    // vector<int> piles = {805306368,805306368,805306368};
    // int h = 1000000000;
    vector<int> piles = {2, 2};
     int h = 4;

    int ans = sol.minEatingSpeed(piles, h);

    return 0;
}