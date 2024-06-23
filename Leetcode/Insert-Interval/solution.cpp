#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int stopIdx;

        for (stopIdx=0; stopIdx<intervals.size(); stopIdx++) {
            if (newInterval[0] <= intervals[stopIdx][1]) {
                break;
            }
            ans.push_back(intervals[stopIdx]);
        }

        while (stopIdx<intervals.size() && intervals[stopIdx][0]<=newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[stopIdx][0]);
            newInterval[1] = max(newInterval[1], intervals[stopIdx][1]);
            stopIdx++;
        }
        ans.push_back(newInterval);

        for (int i=stopIdx; i<intervals.size(); i++) ans.push_back(intervals[i]);

        return ans;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> intervals = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    vector<int> newInterval = {4,11};

    vector<vector<int>> ans = solution.insert(intervals, newInterval);
}