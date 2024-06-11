#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution { 
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i, j, k, sum;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (i=0; i<nums.size(); i++) {
            if (i>0 and nums[i]==nums[i-1]) continue;
            j = i+1;
            k = nums.size()-1;
            while (j < k) {
                sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    while (j < k and nums[j+1] == nums[j]) {
                        j++;
                    }
                    while (k > j and nums[k-1] == nums[k]) {
                        k--;
                    }
                    j++;
                    k--;
                } else if (sum > 0) {
                    k--;
                } else { // sum < 0
                    j++;
                }
            }
        }
        
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums{-1,0,1,2,-1,-4};

    vector<vector<int>> ans = solution.threeSum(nums);
    for (int i=0; i<ans.size(); i++) {
        for (int j=0; j<ans[i].size(); j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}