#include <vector>
using namespace std;

class Solution {
public:
    int countLiveNeighbors(vector<vector<int>>& board, int r, int c) {
        int m = board.size();
        int n = board[0].size();
        int cnt = 0;

        for (int i=max(0, r-1); i<=min(r+1, m-1); i++) {
            for (int j=max(0, c-1); j<=min(c+1, n-1); j++) {
                cnt += board[i][j] & 1;
            }
        }

        cnt -= board[r][c] & 1;

        return cnt;
    }

    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        for (int r=0; r<m; r++) {
            for (int c=0; c<n; c++) {
                int liveNeighbors = countLiveNeighbors(board, r, c);
                
                if (liveNeighbors == 3) board[r][c] |= 2;
                else if (liveNeighbors==2 && board[r][c]==1) board[r][c] |= 2;
            }
        }

        for (int r=0; r<m; r++) {
            for (int c=0; c<n; c++) {
                board[r][c] >>= 1;
            }
        }
    } 
};

int main() {
    Solution solution;

    vector<vector<int>> board = {
        {0,1,0},{0,0,1},{1,1,1},{0,0,0}
    };

    solution.gameOfLife(board);

    return 0;
}