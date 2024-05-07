#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size(), n = matrix[0].size();
        int r = 0, c = 0;

        while (ans.size() != m*n) {
            while (c < n && matrix[r][c] != 101) {
                ans.push_back(matrix[r][c]);
                matrix[r][c] = 101;
                c++;
            }
            c--;
            r++;

            while (r < m && matrix[r][c] != 101) {
                ans.push_back(matrix[r][c]);
                matrix[r][c] = 101;
                r++;
            }
            r--;
            c--;

            while (c >= 0 && matrix[r][c] != 101) {
                ans.push_back(matrix[r][c]);
                matrix[r][c] = 101;
                c--;
            }
            c++;
            r--;

            while (r >= 0 && matrix[r][c] != 101) {
                ans.push_back(matrix[r][c]);
                matrix[r][c] = 101;
                r--;
            }
            r++;
            c++;
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