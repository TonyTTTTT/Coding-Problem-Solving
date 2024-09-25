#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> occur;

        for (auto num : nums) occur[num]++;

        int ans = 0;
        for (auto& itr : occur) {
            int cur = itr.first;
            
            if (cur * 2 == k) {
                ans += itr.second / 2;
                continue;
            }

            auto itr2 = occur.find(k-cur);
            if (itr2 != occur.end()) {
                int pairs = min(itr.second, itr2->second);
                ans += pairs;
                itr.second -= pairs;
                itr2->second -= pairs;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2,5,4,4,1,3,4,4,1,4,4,1,2,1,2,2,3,2,4,2};
    int k = 3;

    int ans = sol.maxOperations(nums, k);

    return 0;
}