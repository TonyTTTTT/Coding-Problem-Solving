#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>> pq(nums.begin(), nums.end());

        for (int i=0; i<k-1; i++) {
            pq.pop();
        }

        return pq.top();
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    int k = 4;

    int ans = solution.findKthLargest(nums, k);
}