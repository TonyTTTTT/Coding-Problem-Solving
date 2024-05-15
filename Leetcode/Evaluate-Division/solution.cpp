#include <vector>
#include <iostream>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;

struct Node {
    string name;
    unordered_map<string, double> out;

    Node (string s) : name(s) {}
};


class Solution {
public:
    double dfs(vector<string> query, unordered_map<string, unordered_map<string, double>>& graph, vector<string>& path) {
        if (!graph.count(query[0]) || !graph.count(query[1])) return -1;

        if (query[0] == query[1]) return 1;

        unordered_map<string, double> outMap = graph[query[0]];

        for (auto node : outMap) {
            if (node.first == query[1]) return node.second;
        }

        for (auto node : outMap) {
            if (find(path.begin(), path.end(), node.first) == path.end()) {
                path.push_back(node.first);
                double res = dfs({node.first, query[1]}, graph, path);
                path.pop_back();

                if (res != -1) {
                    outMap[query[1]] = node.second * res;
                    return outMap[query[1]];
                }
            }
        }

        return -1;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph;
        vector<double> ans;

        for (int i=0; i<equations.size(); i++) {
            graph[equations[i][0]][equations[i][1]] = values[i];
            graph[equations[i][1]][equations[i][0]] = 1 / values[i];
        }


        for (auto query : queries) {
            vector<string> path = {query[0]};
            double res = dfs(query, graph, path);
            ans.push_back(res);
        }


        return ans;
    }
};

int main() {
    Solution solution;
    vector<vector<string>> equations = {
        {"x1","x2"},{"x2","x3"},{"x3","x4"},{"x4","x5"}
    };

    vector<double> values = {3.0,4.0,5.0,6.0};

    vector<vector<string>> queries = {
        {"x1","x5"},{"x5","x2"},{"x2","x4"},{"x2","x2"},{"x2","x9"},{"x9","x9"}
    };

    vector<double> ans = solution.calcEquation(equations, values, queries);
}