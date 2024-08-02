#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rows(9, vector<bool>(9));
        vector<vector<bool>> cols(9, vector<bool>(9));
        vector<vector<bool>> grids(9, vector<bool>(9));

        for (int r=0; r<board.size(); r++) {
            for (int c=0; c<board.size(); c++) {
                int num = board[r][c] - '0' - 1;

                if (num < 0) continue;

                int gridNum = (r/3)*3 + c/3;

                if (rows[r][num] || cols[c][num] || grids[gridNum][num]) return false;
                rows[r][num] = cols[c][num] = grids[gridNum][num] = true;
            }
        }

        return true;
    }
};

int main() {
    Solution solution;
    vector<vector<char>> board = {
        {'8','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}
    };

    bool ans = solution.isValidSudoku(board);

    return 0;
}

