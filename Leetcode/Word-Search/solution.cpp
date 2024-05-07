#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool backTrack(vector<vector<char>>& board, int r, int c, string& word, int wordIdx) {
        if (r<0 || r>=board.size() || c<0 || c>=board[0].size()) return false;

        if (board[r][c] != word[wordIdx]) return false;
        if (wordIdx == word.size()-1) return true;
        char tmp = board[r][c];
        board[r][c] = '0';

        
        bool ans = backTrack(board, r+1, c, word, wordIdx+1) || backTrack(board, r-1, c, word, wordIdx+1) || 
        backTrack(board, r, c+1, word, wordIdx+1) || backTrack(board, r, c-1, word, wordIdx+1);
        
        board[r][c] = tmp;

        return ans;
    }

    bool exist(vector<vector<char>>& board, string word) {

        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[0].size(); j++) {
                if (backTrack(board, i, j, word, 0)) return true;
            }
        }

        return false;
    }
};

int main() {
    vector<vector<char>> board = {
        {'a','a','a'},{'A','A','A'},{'a','a','a'}
    };
    string word = "aAaaaAaaA";
    Solution solution;

    bool ans = solution.exist(board, word);
    __asm("nop");
}