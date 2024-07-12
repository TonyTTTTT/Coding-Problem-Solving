#include <vector>
#include <unordered_map>
#include <set>
#include <iostream>
using namespace std;

void getCost(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight) {
    // Print your answer within the function and return nothing
    unordered_map<int, vector<vector<int>>> adjs;
    
    for (int i=0; i<g_from.size(); i++) {
        adjs[g_from[i]].push_back({g_to[i], g_weight[i]});
        adjs[g_to[i]].push_back({g_from[i], g_weight[i]});
    }
    
    vector<int> costs(g_nodes+1, __INT_MAX__);
    costs[1] = 0;
    
    set<vector<int>> candidates; // set : {{cost, node}}
    candidates.insert({0, 1});
    vector<int> candidate;
    
    while (!candidates.empty()) {
        candidate = *candidates.begin();
        candidates.erase(candidates.begin());
        
        // printf("candidate: %d\n", candidate[1]);
        
        for (auto adj : adjs[candidate[1]]) {
            int cost = max(costs[candidate[1]], adj[1]);
            // printf("cost: %d\n", cost);
            if (cost < costs[adj[0]]) {
                costs[adj[0]] = cost;
                candidates.insert({costs[adj[0]], adj[0]});
            }
        }
    }
    
    // for (auto num : costs) printf("%d ", num); cout<<endl;
    
    if (costs[g_nodes] == __INT_MAX__) printf("NO PATH EXISTS\n");
    else printf("%d\n", costs[g_nodes]);
}

int main() {
    int g_nodes = 5;
    vector<int> g_from = {1,3,1,4,2};
    vector<int> g_to = {2,5,4,5,3};
    vector<int> g_weight = {60,70,120,150,80};

    getCost(g_nodes, g_from, g_to, g_weight);

    return 0;
}