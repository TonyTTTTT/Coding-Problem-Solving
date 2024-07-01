#include <vector>
#include <unordered_map>
#include <stdlib.h>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> v2i;
        
        for (int i=0; i<nums.size(); i++) {
            if (v2i.count(nums[i]) && abs(i-v2i[nums[i]])<=k) return true;
            v2i[nums[i]] = i;
        }

        return false;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1,2,3,1,2,3};
    int k = 4;

    bool ans = solution.containsNearbyDuplicate(nums, k);
}