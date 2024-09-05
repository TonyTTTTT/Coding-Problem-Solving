#include <vector>
#include <stdlib.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        pair<int, int> min_num = {10001, -1};
        pair<int, int> s_min_num = {10001, -1};
        pair<int, int> max_num = {-10001, -1};
        pair<int, int> s_max_num = {-10001, -1};


        for (int i=0; i<arrays.size(); i++) {
            if (arrays[i][0] < min_num.first) {
                s_min_num = min_num;
                min_num = {arrays[i][0], i};
            } else if (arrays[i][0] < s_min_num.first) s_min_num = {arrays[i][0], i};

            if (arrays[i].back() > max_num.first) {
                s_max_num = max_num;
                max_num = {arrays[i].back(), i};
            } else if (arrays[i].back() < s_max_num.first) s_max_num = {arrays[i].back(), i};
        }

        int ans;
        if (min_num.second == max_num.second) {
            ans = max(abs(min_num.first - s_max_num.first), abs(s_min_num.first - max_num.first));
        } else {
            ans = abs(min_num.first - max_num.first);
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> arrays = {{1}, {1}};

    int ans = sol.maxDistance(arrays);

    return 0;
}