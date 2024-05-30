#include <vector>
#include <unordered_set>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool diffuse(vector<vector<char>>& board, vector<pair<int, int>>& region, int i, int j) {
        if (i<0 || i==board.size() || j<0 || j==board[0].size() || \
            board[i][j] != 'O') return false;

        region.push_back({i, j});
        board[i][j] = 'S';

        bool reachBorder = diffuse(board, region, i+1, j);
        reachBorder = diffuse(board, region, i-1, j) || reachBorder;
        reachBorder = diffuse(board, region, i, j+1) || reachBorder;
        reachBorder = diffuse(board, region, i, j-1) || reachBorder;

        reachBorder = reachBorder || i==0 || i==board.size()-1 || j==0 || j==board[0].size()-1;

        return reachBorder;
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<int> step = {n, m-1};
        vector<vector<int>> action = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int cnt = 0;
        int r=0, c=-1;
        vector<vector<bool>> canReachBorder(m, vector(n, false));


        while (step[cnt%2]) {
            for (int i=0; i<step[cnt%2]; i++) {
                r += action[cnt%4][0];
                c += action[cnt%4][1];

                canReachBorder[r][c] = board[r][c] == 'O' && ( r-1<0 || r+1==m || c-1<0 || c+1==n ||\
                 canReachBorder[r-1][c] ||  canReachBorder[r+1][c] ||\
                  canReachBorder[r][c-1] || canReachBorder[r][c+1]);
            }
            step[cnt%2]--;
            cnt++;
        }


        r = -1, c = 0;
        cnt = 0;
        action = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        step = {m, n-1};
        while (step[cnt%2]) {
            for (int i=0; i<step[cnt%2]; i++) {
                r += action[cnt%4][0];
                c += action[cnt%4][1];

                canReachBorder[r][c] = board[r][c] == 'O' && ( r-1<0 || r+1==m || c-1<0 || c+1==n ||\
                 canReachBorder[r-1][c] ||  canReachBorder[r+1][c] ||\
                  canReachBorder[r][c-1] || canReachBorder[r][c+1]);
            }
            step[cnt%2]--;
            cnt++;
        }

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (!canReachBorder[i][j]) board[i][j] = 'X';
            }
        }

    }
};

int main() {
    Solution solution;
    vector<vector<char>> board = {
        // {'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}
        // {'X'}
        {'O'}
        // {'O','O','O','O','X','X'},{'O','O','O','O','O','O'},{'O','X','O','X','O','O'},{'O','X','O','O','X','O'},{'O','X','O','X','O','O'},{'O','X','O','O','O','O'}
        // {'O','O','O','O','X','X'},{'O','O','O','O','O','O'},{'O','X','O','X','O','O'},{'O','X','O','O','X','O'},{'O','X','O','X','O','O'},{'O','X','O','O','O','O'}
        // {'X','O','X','O','X','O'},{'O','X','O','X','O','X'},{'X','O','X','O','X','O'},{'O','X','O','X','O','X'}
    };

    solution.solve(board);

    __asm("nop");
}