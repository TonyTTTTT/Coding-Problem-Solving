#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        vector<vector<int>> dirVec = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int m = matrix.size(), n = matrix[0].size();
        int r = 0, c = -1;

        vector<int> step = {n, m-1};
        int dir = 0;

        while (step[dir%2] > 0) {
           for (int i=1; i <= step[dir%2]; i++) {
                r += dirVec[dir][0];
                c += dirVec[dir][1];

                ans.push_back(matrix[r][c]);
           }
           step[dir%2]--;
           dir = (dir+1) % 4;
        }

        return ans;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> matrix = {
        {1,2,3,4},{5,6,7,8},{9,10,11,12}
    };

    vector<int> ans = solution.spiralOrder(matrix);
}