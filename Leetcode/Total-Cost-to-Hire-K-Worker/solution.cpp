#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<int>> pqFromS;
        priority_queue<int, vector<int>, greater<int>> pqFromE;
        int fromS = -1, fromE = costs.size();

        for (int i=0; i<candidates; i++) {
            if (fromS+1 == fromE) break;
            pqFromS.push(costs[++fromS]);
            if (fromS+1 == fromE) break;
            pqFromE.push(costs[--fromE]);
        }

        long long ans = 0;
        for (int i=0; i<k; i++) {
            if (pqFromE.empty() || (!pqFromS.empty() && pqFromS.top() <= pqFromE.top())) {
                ans += pqFromS.top();
                pqFromS.pop();
                if (fromS+1 < fromE) pqFromS.push(costs[++fromS]);
            } else {
                ans += pqFromE.top();
                pqFromE.pop();
                if (fromE-1 > fromS) pqFromE.push(costs[--fromE]);
            }
        }

        return ans;
    }
};
int main() {
    Solution sol;
    vector<int> costs = {57,33,26,76,14,67,24,90,72,37,30};
    int k = 11;
    int candidates = 2;

    long long ans = sol.totalCost(costs, k, candidates);

    return 0;
}