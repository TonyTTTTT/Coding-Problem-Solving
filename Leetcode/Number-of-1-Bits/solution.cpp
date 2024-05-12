#include <vector>
using namespace std;

class Solution {
public:
    int hammingWeight(int n) {
        vector<int> twoPower = {1};
        int ans = 0;

        for (long long i=2; i<=n; i*=2) {
            twoPower.push_back(i);
        }

        for (int i=twoPower.size()-1; i>=0; i--) {
            if (n >= twoPower[i]) {
                n -= twoPower[i];
                ans++;
            }

            if (n == 0) break;
        }

        return ans;
    }
};

int main() {
    Solution solution;
    int n = 2147483645;

    int ans = solution.hammingWeight(n);
}