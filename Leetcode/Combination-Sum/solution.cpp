#include <vector>
using namespace std;

class Solution {
    void backTrack(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& curComb, int startIdx) {
        if (target == 0) {
            ans.push_back(curComb);
            return;
        }
        if (target < 0) return;

        for (int i=startIdx; i<candidates.size(); i++) {
            curComb.push_back(candidates[i]);
            backTrack(candidates, target-candidates[i], ans, curComb, i);
            curComb.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curComb;

        backTrack(candidates, target, ans, curComb, 0);

        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> candidates = {2,3,5};
    int target = 8;

    vector<vector<int>> ans = solution.combinationSum(candidates, target);
}