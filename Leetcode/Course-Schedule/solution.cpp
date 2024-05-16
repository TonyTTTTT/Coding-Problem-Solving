#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
using namespace std;


struct Graph {
    vector<vector<int>> adj;
    int n;

    Graph(int num) {
        n = num;
        adj.resize(num);
    }
};

class Solution {
public:
    // true: has cycle
    bool dfs(vector<vector<int>>& graph, int currentCourse, vector<bool>& path, vector<bool>& visited) {
        if (path[currentCourse]) return true;
        path[currentCourse] = true;

        for (int course : graph[currentCourse]) {
            if (!visited[course]) {
                bool hasCycle = dfs(graph, course, path, visited);
                if (hasCycle) return hasCycle;       
            }
        }

        visited[currentCourse] = true;
        path[currentCourse] = false;

        return false;
    }

    // true: has cycle
    bool bfs(vector<vector<int>>& graph, vector<int> indegrees, int numCourses) {

        for (int i=0; i<numCourses; i++) {
            int currentCourse;
            for (currentCourse=0; currentCourse<indegrees.size(); currentCourse++) {
                if (indegrees[currentCourse] == 0) break;
            }
            if (currentCourse == indegrees.size()) return true;

            for (auto neighbor : graph[currentCourse]) indegrees[neighbor]--;

            indegrees[currentCourse] = -1;
        }

        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (prerequisites.size() == 0) return true;

        vector<vector<int>> graph(numCourses);
        vector<int> indegrees(numCourses, -1);
        int connectedCourses = 0;

        for (auto& prerequisite : prerequisites) {
            graph[prerequisite[1]].push_back(prerequisite[0]);

            if (indegrees[prerequisite[0]] == -1) {
                indegrees[prerequisite[0]] = 0;
                connectedCourses++;
            }
            if (indegrees[prerequisite[1]] == -1) {
                indegrees[prerequisite[1]] = 0;
                connectedCourses++;
            }

            indegrees[prerequisite[0]]++;
        }

        // vector<bool> visited(numCourses, false);
        // vector<bool> path(numCourses, false);

        // for (int course=0; course<graph.size(); course++) {
        //     if (!visited[course]) {
        //         bool hasCycle = dfs(graph, course, path, visited);
        //         if (hasCycle) return false;
        //     }
        // }

        bool hasCycle = bfs(graph, indegrees, connectedCourses);

        return !hasCycle;
    }
};

int main() {
    Solution solution;
    int numCourses = 5;
    vector<vector<int>> prerequisites = {
       {1,4},{2,4},{3,1},{3,2}
    };

    bool ans = solution.canFinish(numCourses, prerequisites);

    __asm("nop");
}