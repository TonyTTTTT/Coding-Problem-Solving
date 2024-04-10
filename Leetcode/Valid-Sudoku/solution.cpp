#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValid(vector<char> sub_board) {
        bool appear[10] = {0};
        int num;
        for (int i=0; i<sub_board.size(); i++) {
            num = sub_board[i] - '0';
            if (num == -2) {
                continue;
            } else if (appear[num] == true) {
                return false;
            } else {
                appear[num] = true;
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        bool ans;
        vector<char> sub_board;

        for (int i=0; i<board.size(); i++) { 
            ans = isValid(board[i]);
            if (ans == false) {
                return ans;
            }
        }

        for (int i=0; i<9; i++) {
            sub_board.clear();
            for (int j=0; j<board.size(); j++) {
                sub_board.push_back(board[j][i]);
            }
            ans = isValid(sub_board);
            if (ans == false) {
                return ans;
            }
        }

        for (int i=0; i<9; i++) {
            sub_board.clear();
            for (int j=(i%3)*3; j<((i%3)+1)*3; j++) {
                for (int k=(i/3)*3; k<(i/3)*3+3; k++) {
                    sub_board.push_back(board[j][k]);
                }
            }
            ans = isValid(sub_board);
            if (ans == false) {
                return ans;
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;
    vector<vector<char>> board{
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    bool ans = solution.isValidSudoku(board);

    return 0;
}