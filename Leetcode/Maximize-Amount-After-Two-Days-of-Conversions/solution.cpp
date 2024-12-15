#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

class Solution {
    void traverse(unordered_map<string, vector<pair<string, double>>>& graph, string cur, double val, double& ans, string init, unordered_set<string> visited) {
        if (cur == init) {
            ans = max(ans, val);
            return;
        }

        visited.insert(cur);
        
        for (auto neighbor : graph[cur]) {
            if (!visited.count(neighbor.first)) {
                traverse(graph, neighbor.first, neighbor.second * val, ans, init, visited);
            }
        }
    }
    void traverse(unordered_map<string, vector<pair<string, double>>>& graph, string cur, double val, unordered_set<string> visited, unordered_map<string, double>& firstDayState) {
        firstDayState[cur] = val;

        visited.insert(cur);
        
        for (auto neighbor : graph[cur]) {
            if (!visited.count(neighbor.first)) {
                traverse(graph, neighbor.first, neighbor.second * val, visited, firstDayState);
            }
        }
    }
public:
    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
        double ans = 1;
        unordered_map<string, vector<pair<string, double>>> graph;
        unordered_map<string, double> firstDayState;
        firstDayState[initialCurrency] = 1;

        for (int i=0; i<pairs1.size(); i++) {
            graph[pairs1[i][0]].push_back({pairs1[i][1], rates1[i]});
        }        

        unordered_set<string> visited;
        traverse(graph, initialCurrency, 1, visited, firstDayState);

        graph.clear();
        for (int i=0; i<pairs2.size(); i++) {
            graph[pairs2[i][0]].push_back({pairs2[i][1], rates2[i]});
            graph[pairs2[i][1]].push_back({pairs2[i][0], 1/rates2[i]});
        }

        for (auto itr=firstDayState.begin(); itr!=firstDayState.end(); itr++) {
            unordered_set<string> visited;
            traverse(graph, itr->first, itr->second, ans, initialCurrency, visited);
        }

        return ans;
    }
};

int main() {
    Solution sol;
    string initialCurrency = "ACB";
    vector<vector<string>> pairs1 = {{"SFE","Z"},{"ACB","SFE"}};
    vector<double> rates1 = {9.1,2.4};
    vector<vector<string>> pairs2 = {{"SFE","Z"},{"ACB","SFE"}};
    vector<double> rates2 = {2.8,5.0};

    double ans = sol.maxAmount(initialCurrency, pairs1, rates1, pairs2, rates2);

    return 0;
}