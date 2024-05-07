#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool binarySearch(vector<vector<int>>& matrix, int target, int first, int last) {
        if (first > last) return false;

        int idx = (first + last) / 2;
        int r = idx / matrix[0].size();
        int c = idx % matrix[0].size();

        if (matrix[r][c] == target) {
            return true;
        } else if (matrix[r][c] > target) {
            return binarySearch(matrix, target, first, idx-1);
        } else { // matrix[r][c] < target
            return binarySearch(matrix, target, idx+1, last);
        }
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, r = matrix.size() * matrix[0].size() - 1;
        int m = matrix.size(), n = matrix[0].size();

        while (l <= r) {
            int mid = (l + r) / 2;

            if (matrix[mid/n][mid%n] == target) {
                return true;
            } else if (matrix[mid/n][mid%n] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        return false;
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1,3,5,7},{10,11,16,20},{23,30,34,60}
    };
    int target = 60;
    Solution solution;

    bool ans = solution.searchMatrix(matrix, target);
    __asm("nop");
}