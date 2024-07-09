#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int totalProfit = 0;
        
        for (int i=1; i<prices.size(); i++) {
            if (prices[i] > prices[i-1]) totalProfit += prices[i] - prices[i-1];
        }

        return totalProfit;
    }
};

int main() {
    Solution solution;
    vector<int> prices = {7,1,5,3,6,4};

    int ans = solution.maxProfit(prices);

    return 0;
}