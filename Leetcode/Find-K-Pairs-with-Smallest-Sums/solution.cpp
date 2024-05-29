#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        auto cmp = [&] (pair<int, int> a, pair<int, int> b) {
            return nums1[a.first]+nums2[a.second] > nums1[b.first]+nums2[b.second];
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
        vector<vector<int>> ans;

        q.push({0, 0});

        for (int i=0; i<k; i++) {
            pair<int, int> top = q.top(); q.pop();

            if (top.first + 1 < nums1.size()) q.push({top.first + 1, top.second});
            if (top.first == 0 && top.second + 1 < nums2.size()) q.push({top.first, top.second+1});

            ans.push_back({nums1[top.first], nums2[top.second]});
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1,1,2};
    vector<int> nums2 = {1,2,3};
    int k = 3;

    vector<vector<int>> ans = sol.kSmallestPairs(nums1, nums2, k);
}