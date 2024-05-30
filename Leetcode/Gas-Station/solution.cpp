#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0;
        int startSum = 0;
        int start = 0;

        for (int i=0; i<gas.size(); i++) {
            int remain = gas[i] - cost[i];
            sum += remain;
            startSum += remain;

            if (startSum < 0) {
                start = i+1;
                startSum = 0;
            }
        }
 
        return sum < 0 ? -1 : start;
    }
};

int main() {
    Solution solution;
    vector<int> gas = {5,1,2,3,4};
    vector<int> cost = {4,4,1,5,1};

    int ans = solution.canCompleteCircuit(gas, cost);

    __asm("nop");
}