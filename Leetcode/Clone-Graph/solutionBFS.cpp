#include "../Node.h"
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        unordered_map<Node*, Node*> map;
        queue<Node*> q;
        q.push(node);
        map[node] = new Node(node->val);

        while(!q.empty()) {
            Node* n = q.front();q.pop();

            for (auto neighbor : n->neighbors) {
                if (!map.count(neighbor)) {
                    q.push(neighbor);
                    map[neighbor] = new Node(neighbor->val);
                }
                map[n]->neighbors.push_back(map[neighbor]);
            }
        }

        return map[node];
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