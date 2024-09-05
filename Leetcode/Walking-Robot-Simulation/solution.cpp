#include <vector>
#include <set>
#include <stdlib.h>
using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int, int>> obstacles_set;
        for (auto obstacle : obstacles) {
            obstacles_set.insert({obstacle[0], obstacle[1]});
        }

        vector<vector<int>> direct = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int direct_idx = 0;
        
        int cur_x, cur_y;
        cur_x = cur_y = 0;
        int ans = 0;

        for (auto command : commands) {
            if (command == -1) direct_idx = (direct_idx+1+4) % 4;
            else if (command == -2) direct_idx = (direct_idx-1+4) % 4;
            else {
                while(command-- > 0) {
                    int new_x = cur_x + direct[direct_idx][0];
                    int new_y = cur_y + direct[direct_idx][1];
                    if (obstacles_set.count({new_x, new_y})) break;

                    cur_x = new_x;
                    cur_y = new_y;
                }
                ans = max(ans, cur_x*cur_x + cur_y*cur_y);
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> commands = {-2,8,3,7,-1};
    vector<vector<int>> obstacles = {{-4,-1},{1,-1},{1,4},{5,0},{4,5},{-2,-1},{2,-5},{5,1},{-3,-1},{5,-3}};

    int ans = sol.robotSim(commands, obstacles);

    return 0;
}