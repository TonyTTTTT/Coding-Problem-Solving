#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;

        int ans  = INT_MAX;

        for (int i=0; i<coins.size(); i++) {
            if (coins[i] <= amount) {
                int tmp = coinChange(coins, amount-coins[i]);

                if (tmp != -1) ans = min(ans, tmp);
            }
        }

        if (ans == INT_MAX) return -1;
        
        ans++;
        return ans;
    }
};

int main() {
    Solution solution;

    vector<int> coins = {2,4};
    int amount = 11;

    int ans = solution.coinChange(coins, amount);

    __asm("nop");
}