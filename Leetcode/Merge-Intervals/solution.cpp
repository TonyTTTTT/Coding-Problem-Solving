#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> mySort(vector<vector<int>> v) {
        if (v.size() == 1) {
            return v;
        }

        vector<vector<int>> l = mySort({v.begin(), v.begin()+v.size()/2});
        vector<vector<int>> r = mySort({v.begin()+v.size()/2, v.end()});

        vector<vector<int>> sorted;
        int idxL = 0, idxR=0;

        while (idxL<l.size() && idxR<r.size()) {
            if (l[idxL][0] <= r[idxR][0]) {
                sorted.push_back(l[idxL++]);
            } else {
                sorted.push_back(r[idxR++]);
            }
        }

        for (int i=idxL; i<l.size(); i++) {
            sorted.push_back(l[i]);
        }
        for (int i=idxR; i<r.size(); i++) {
            sorted.push_back(r[i]);
        }

        return sorted;
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        intervals = mySort(intervals);
        vector<vector<int>> ans{intervals[0]};
        int idx = 0;

        for (int i=1; i<intervals.size(); i++) {
            if (intervals[i][0] <= ans[idx][1] && intervals[i][1] >= ans[idx][0]) {
                ans[idx][0] = min(ans[idx][0], intervals[i][0]);
                ans[idx][1] = max(ans[idx][1], intervals[i][1]); 
            } else {
                ans.push_back(intervals[i]);
                idx++;
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> intervals{{2,3},{4,5},{6,7},{8,9},{1,10}};

    vector<vector<int>> ans = solution.merge(intervals);
}