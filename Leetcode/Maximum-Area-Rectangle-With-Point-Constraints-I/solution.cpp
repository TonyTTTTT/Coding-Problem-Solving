#include <set>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    int match(int y1, int y2, int x, unordered_map<int, set<int>>& y2x) {
        auto itr1 = next(y2x[y1].find(x));
        auto itr2 = next(y2x[y2].find(x));

        if (*itr1 == *itr2) return *itr1;
        return -1;
    }
    bool checkInside(int x1, int x2, int y1, int y2, unordered_map<int, set<int>>& x2y, unordered_map<int, set<int>>& y2x) {
        for (int i=x1; i<=x2; i++) {
            for (int j=y1+1; j<y2; j++) {
                if (x2y.count(i) && x2y[i].find(j) != x2y[i].end()) return false;
            }
        }
        return true;
    }
public:
    int maxRectangleArea(vector<vector<int>>& points) {
        unordered_map<int, set<int>> x2y;
        unordered_map<int, set<int>> y2x;
        int ans = -1;

        for (auto point : points) {
            x2y[point[0]].insert(point[1]);
            y2x[point[1]].insert(point[0]);
        }

        for (auto itr=x2y.begin(); itr!=x2y.end(); itr++) {
            if (itr->second.size() >= 2) {
                auto setItr1 = itr->second.begin();
                auto setItr2 = next(itr->second.begin());
                while (setItr2 != itr->second.end()) {
                    int nextX = match(*setItr1, *setItr2, itr->first, y2x);
                    if (nextX >= 0) {
                        if (checkInside(itr->first, nextX, *setItr1, *setItr2, x2y, y2x)) {
                            ans = max(ans, (nextX - itr->first) * (*setItr2 - *setItr1));   
                        } 
                    }
                    setItr1++;
                    setItr2++;
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> points = {{15,93},{5,33},{15,33},{5,93},{30,93},{30,33},{35,93},{35,33}};
    int ans = sol.maxRectangleArea(points);

    return 0;
}

