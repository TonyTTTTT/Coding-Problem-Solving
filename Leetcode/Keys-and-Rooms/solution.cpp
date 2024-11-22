#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    void dfs(int cur, vector<vector<int>>& rooms, vector<bool>& visited) {
        visited[cur] = true;
        for (int neighbor : rooms[cur]) {
            if (!visited[neighbor]) dfs(neighbor, rooms, visited);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);

        dfs(0, rooms, visited);

        for (bool hadVisited : visited) {
            if (!hadVisited) return false;
        }

        return true;
    }
};

int main() {
    // vector<vector<int>> rooms = {{1,3},{1,4},{2,3,4,1},{},{4,3,2}};
    vector<vector<int>> rooms = {{1,3},{3,0,1},{2},{0}};
    Solution sol;

    bool ans = sol.canVisitAllRooms(rooms);

    return 0;
}