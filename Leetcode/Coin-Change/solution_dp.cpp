#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX-1);
        dp[0] = 0;

        for (int i=1; i<=amount; i++) {
            for (auto coin : coins) {
                if (i-coin >= 0) {
                    dp[i] = min(dp[i], dp[i-coin]+1);
                }
            }
        }

        if (dp[amount] == INT_MAX-1) return -1;

        return dp[amount];
    }
};

int main() {
    Solution solution;

    vector<int> coins = {1,2,5};
    int amount = 100;

    int ans = solution.coinChange(coins, amount);

    __asm("nop");
}