#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> friends;
        for (int i=1; i<=n; i++) {
            friends.push_back(i);
        }

        int current = 0;
        while (friends.size() != 1) {
            current += (k-1);
            current = current % friends.size();
            friends.erase(friends.begin()+current);
        }
        
        return friends[0];
    }
};

int main() {
    Solution solution;
    int n = 6;
    int k = 5;

    int ans = solution.findTheWinner(n, k);
    __asm("nop");
}