// you can use includes, for example:
// #include <algorithm>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // Implement your solution here
    vector<pair<int, int>> AWithIdx;
    for (int i=0; i<A.size(); i++) {
        AWithIdx.push_back({A[i], i});
    }

    sort(AWithIdx.begin(), AWithIdx.end());

    int ans = 0;
    for (int i=0; i<AWithIdx.size(); i++) {
        ans += max(0, i-AWithIdx[i].second);
        if (ans > 1000000000) return -1;
    }

    return ans;
}

int main() {
    vector<int> A = {-1, 6, 3, 4, 7, 4, 2};

    int ans = solution(A);

    return 0;
}