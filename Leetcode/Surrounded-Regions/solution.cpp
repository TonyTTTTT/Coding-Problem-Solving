#include <vector>
using namespace std;

class Solution {
public:
    void diffuse(vector<vector<char>>& board, int i, int j) {
        if (i<0 || i==board.size() || j<0 || j==board[0].size() || \
            board[i][j] != 'O') return;

        board[i][j] = 'S';

        diffuse(board, i+1, j);
        diffuse(board, i-1, j);
        diffuse(board, i, j+1);
        diffuse(board, i, j-1);
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        for (int i=0; i<m; i++) {
            if (board[i][0] == 'O') diffuse(board, i, 0);
            if (board[i][n-1] == 'O') diffuse(board, i, n-1);
        }

        for (int j=0; j<n; j++) {
            if (board[0][j] == 'O') diffuse(board, 0, j);
            if (board[m-1][j] == 'O') diffuse(board, m-1, j);
        }

        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[0].size(); j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'S') board[i][j] = 'O';
            }
        }

    }
};

int main() {
    Solution solution;
    vector<vector<char>> board = {
        {'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}
        // {'X'}
        // {'O'}
        // {'O','O','O','O','X','X'},{'O','O','O','O','O','O'},{'O','X','O','X','O','O'},{'O','X','O','O','X','O'},{'O','X','O','X','O','O'},{'O','X','O','O','O','O'}
        // {'O','O','O','O','X','X'},{'O','O','O','O','O','O'},{'O','X','O','X','O','O'},{'O','X','O','O','X','O'},{'O','X','O','X','O','O'},{'O','X','O','O','O','O'}
        // {'X','O','X','O','X','O'},{'O','X','O','X','O','X'},{'X','O','X','O','X','O'},{'O','X','O','X','O','X'}
    };

    solution.solve(board);

    __asm("nop");
}