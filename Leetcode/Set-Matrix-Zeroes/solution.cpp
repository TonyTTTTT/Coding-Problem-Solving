#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0 = 1;
        int m = matrix.size(), n = matrix[0].size();

        for (int i=0; i<m; i++) {
            if (matrix[i][0] == 0) col0 = 0;
            for (int j=1; j<n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }

        for (int i=m-1; i>=0; i--) {
            for (int j=n-1; j>=1; j--) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
            }
            if (col0 == 0) matrix[i][0] = 0;
        }
    }
};

int main() {
    Solution solution;
    vector<vector<int>> matrix = {
        {1,2,3,4},{5,0,7,8},{0,10,11,12},{13,14,15,0}
    };

    solution.setZeroes(matrix);
    __asm("nop");
}