#include "../Node.h"
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    Node* dfs(Node* node, unordered_map<Node*, Node*>& map) {
        map[node] = new Node(node->val);

        for (auto neighbor : node->neighbors) {
            if (!map.count(neighbor)){
                map[node]->neighbors.push_back(dfs(neighbor, map));
            }
            else map[node]->neighbors.push_back(map[neighbor]);
        }

        return map[node];
    }

    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        unordered_map<Node*, Node*> map;

        Node* ans = dfs(node, map);

        return ans;
    }
};

int main() {
    Solution solution;

    vector<Node*> nodes;

    for (int i=1; i<=4; i++) nodes.push_back(new Node(i));

    nodes[0]->neighbors = {nodes[1], nodes[3]};
    nodes[1]->neighbors = {nodes[0], nodes[2]};
    nodes[2]->neighbors = {nodes[1], nodes[3]};
    nodes[3]->neighbors = {nodes[0], nodes[2]};

    Node* ans = solution.cloneGraph(nodes[0]);
}