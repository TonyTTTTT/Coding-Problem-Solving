#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    void convertLabelToIdx(int n, int label, int& r, int& c) {
        r = (label-1) / n;
        c = r%2 == 0 ?  ((label-1) % n) : n - 1 - ((label-1) % n);
        r = n - 1 - r;
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int dest = n*n;
        int steps = 1;
        int r, c;
        queue<int> q;
        q.push(1);

        while(!q.empty()) {
            int nextStepAvail = q.size();
            for (int i=0; i<nextStepAvail; i++) {
                int curSquare = q.front(); q.pop();
                for (int j=1; j<=6; j++) {
                    int nextCandidate;
                    convertLabelToIdx(n, curSquare+j, r, c);
                    
			        if (board[r][c] == -1) nextCandidate = curSquare+j;
			        else nextCandidate = board[r][c];

                    if (nextCandidate == dest) return steps;
                    
                    if (board[r][c] != -2) {
                        q.push(nextCandidate);
                        board[r][c] = -2;
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> board = {
        {-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,35,-1,-1,13,-1},{-1,-1,-1,-1,-1,-1},{-1,15,-1,-1,-1,-1}
    };

    int ans = solution.snakesAndLadders(board);
}