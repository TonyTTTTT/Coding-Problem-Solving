#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        k = k % n;
        if (k==0) return;
        
        int start = n - k;
        int idx = start;

        do {
            ans.push_back(nums[idx]);
            idx = (idx+1) % n;
        } while (idx != start);

        nums = ans;

        return;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1};
    int k = 0;
    
    solution.rotate(nums, k);
}