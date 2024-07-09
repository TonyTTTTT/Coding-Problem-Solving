#include <vector>
using namespace std;

int twoStacks(int maxSum, vector<int> a, vector<int> b) {
    int n = a.size(), m = b.size();
    vector<int> aSum(n+1);
    vector<int> bSum(m+1);
    for (int i=1; i<=n; i++) aSum[i] = aSum[i-1] + a[i-1];
    for (int i=1; i<=m; i++) bSum[i] = bSum[i-1] + b[i-1];
    
    int ans = 0;
    int aIdx = 0, bIdx=m;
    
    while (aIdx<=n && bIdx>=0) {
        if (aSum[aIdx] + bSum[bIdx] > maxSum) bIdx--;
        else {
            ans = max(ans, aIdx+bIdx);
            aIdx++;
        }
    }
    
    aIdx = n, bIdx=0;
    
    while (aIdx>=0 && bIdx<m) {
        if (aSum[aIdx] + bSum[bIdx] > maxSum) aIdx--;
        else {
            ans = max(ans, aIdx+bIdx);
            bIdx++;
        }
    }
    
    return ans;
}


int main() {
    vector<int> a = {4,11,16,0,18,17,9,13,7,12,16,19,2,15,5,13,1,10,0,8,0,6,16,12,15,7,1,6,19,16,2};
    vector<int> b = {15,8,11,16,6,0,5,11,7,9,8,6,3,3,4,8,17,14,9,5,15,15,1,19,10,0,12,8,11,9,11,18,17,14};
    int maxSum = 5;

    int ans = twoStacks(maxSum, a, b);

    return 0;
}