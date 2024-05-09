#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int lmin = INT_MAX;

        for (int i=0; i<prices.size(); i++) {
            if (prices[i] < lmin) lmin = prices[i];

            if (prices[i] - lmin > ans) ans = prices[i] - lmin;
        }

        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> prices = {2, 7, 1, 4};

    int ans = solution.maxProfit(prices);
}