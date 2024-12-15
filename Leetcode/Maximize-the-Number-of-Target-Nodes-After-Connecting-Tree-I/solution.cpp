#include <vector>
#include <unordered_set>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {   
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size()+1;
        int m = edges2.size()+1;
        vector<vector<int>> t1(n);
        vector<vector<int>> t2(m);
        vector<int> t1Cnt(n);
        vector<int> t2Cnt(m);
        

        for (auto edge : edges1) {
            t1[edge[0]].push_back(edge[1]);
            t1[edge[1]].push_back(edge[0]);
        }
        for (auto edge : edges2) {
            t2[edge[0]].push_back(edge[1]);
            t2[edge[1]].push_back(edge[0]);            
        }

        for (int i=0; i<t1.size(); i++) {
            unordered_set<int> s = {i};
            queue<int> q;
            q.push(i);
            for (int j=0; j<k; j++) {
                int qSize = q.size();
                for (int l=0; l<qSize; l++) {
                    int cur = q.front(); q.pop();
                    for (int neighbor : t1[cur]) {
                        if (!s.count(neighbor)) {
                            q.push(neighbor);
                            s.insert(neighbor);
                        }
                    }
                }
            }
            t1Cnt[i] = s.size();
        }

        for (int i=0; i<t2.size(); i++) {
            unordered_set<int> s;
            if (k-1>=0) s.insert(i);
            queue<int> q;
            q.push(i);
            for (int j=0; j<k-1; j++) {
                int qSize = q.size();
                for (int l=0; l<qSize; l++) {
                    int cur = q.front(); q.pop();
                    for (int neighbor : t2[cur]) {
                        if (!s.count(neighbor)) {
                            q.push(neighbor);
                            s.insert(neighbor);
                        }
                    }
                }
            }
            t2Cnt[i] = s.size();
        }

        vector<int> ans(n);
        int maxT2Cnt = *max_element(t2Cnt.begin(), t2Cnt.end());
        for (int i=0; i<n; i++) {
            ans[i] = t1Cnt[i] + maxT2Cnt;
        }

        return ans;
    }
};

int main() {
    Solution sol;
    // vector<vector<int>> edges1 = {{0,1},{0,2},{2,3},{2,4}};
    // vector<vector<int>> edges2 = {{0,1},{0,2},{0,3},{2,7},{1,4},{4,5},{4,6}};
    // int k = 2;
    vector<vector<int>> edges1 = {{0, 1}};
    vector<vector<int>> edges2 = {{0, 1}};
    int k= 0;

    vector<int> ans = sol.maxTargetNodes(edges1, edges2, k);

    return 0;
}