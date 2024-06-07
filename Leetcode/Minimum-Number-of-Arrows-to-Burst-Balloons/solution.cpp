#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int ans = 1;
        int curEnd = points[0][1];

        for (int i=0; i<points.size(); i++) {
            if (points[i][0]<=curEnd) {
                curEnd = min(curEnd, points[i][1]);
            } else {
                ans++;
                curEnd = points[i][1];
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> points = {{9,12},{1,10},{4,11},{8,12},{3,9},{6,9},{6,7}};

    int ans = solution.findMinArrowShots(points);
}