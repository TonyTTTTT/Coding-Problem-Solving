#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    void combine(int n, int k, vector<int>& path, int cur, vector<vector<int>>& ans) {
        if (k == 0) {
            ans.push_back(path);
            return;
        }

        for (int i=cur+1; i<=n; i++) {
            path.push_back(i);
            combine(n, k-1, path, i, ans);
            path.pop_back();
        }

        return;
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> path;
        vector<vector<int>> ans;

        combine(n, k, path, 0, ans);

        return ans;
    }
};

int main() {
    Solution solution;
    int n = 10;
    int k = 3;

    vector<vector<int>> ans = solution.combine(n, k);
}