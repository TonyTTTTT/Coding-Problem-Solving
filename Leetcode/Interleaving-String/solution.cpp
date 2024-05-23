#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isInterleave(string& s1, string& s2, string& s3, vector<vector<int>>& mem, int i, int j) {
        if (i == s1.size()) {
            mem[i][j] = s2.substr(0, s2.size()-j) == s3.substr(0, s3.size()-i-j);
            return mem[i][j];
        } else if (j == s2.size())  {
            mem[i][j] = s1.substr(0, s1.size()-i) == s3.substr(0, s3.size()-i-j);
            return mem[i][j];
        } else if (i+j == s3.size()) {
            mem[i][j] = false;
            return mem[i][j];
        }

        if (mem[i+1][j] == -1) {
            mem[i+1][j] = isInterleave(s1, s2, s3, mem, i+1, j);
        }
        bool ans1 = (s1[s1.size()-1-i] == s3[s3.size()-1-i-j]) && mem[i+1][j];

        if (mem[i][j+1] == -1) {
            mem[i][j+1] = isInterleave(s1, s2, s3, mem, i, j+1);
        }            
        bool ans2 = (s2[s2.size()-1-j] == s3[s3.size()-1-i-j]) && mem[i][j+1];

        mem[i][j] = ans1 || ans2;

        return mem[i][j];
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int>> mem(s1.size()+1, vector<int>(s2.size()+1, -1));

        return isInterleave(s1, s2, s3, mem, 0, 0);
    }
};

int main() {
    Solution solution;
    string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";

    bool ans = solution.isInterleave(s1, s2, s3);

    __asm("nop");
}