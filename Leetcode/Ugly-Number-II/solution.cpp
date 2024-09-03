#include <set>
#include <vector>
#include <queue>
using namespace std;

class Solution {
    int findMin(vector<queue<long>>& candidate) {
        int minQIdx = candidate[0].front() < candidate[1].front() ? 0 : 1;
        minQIdx = candidate[minQIdx].front() < candidate[2].front() ? minQIdx : 2;

        int curMin = candidate[minQIdx].front();
        candidate[minQIdx].pop();
        return curMin;
    }
public:
    int nthUglyNumber(int n) {
        if (n <= 6) return n;

        vector<int> uglys = {1};
        vector<queue<long>> candidate(3); 
        int idx = 0;

        while (uglys.size() < n) {
            long cur = uglys[idx];
            candidate[0].push(cur*2);
            candidate[1].push(cur*3);
            candidate[2].push(cur*5);

            int curMin = findMin(candidate);
            while (curMin == uglys[idx]) {
                curMin = findMin(candidate);
            }
            uglys.push_back(curMin);
            idx++;
        }

        return uglys.back();
    }
};

int main() {
    Solution solution;
    int n = 10;

    int ans = solution.nthUglyNumber(n);
}