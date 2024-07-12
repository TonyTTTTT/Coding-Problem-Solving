#include <vector>
#include <iostream>
using namespace std;

string larrysArray(vector<int> A) {
    for (int i=1; i<=A.size(); i++) {
        int j;
        int destIdx = i-1;
        for (j=destIdx; j<A.size(); j++) {
            if (A[j] == i) break;
        }
        
        while (j != destIdx) {
            if (destIdx == A.size()-2) return "NO";
            if (j-destIdx >= 2) {
                int tmp = A[j];
                A[j] = A[j-1];
                A[j-1] = A[j-2];
                A[j-2] = tmp;
                
                j -= 2;
            } else {
                int tmp = A[j];
                A[j] = A[j+1];
                A[j+1] = A[j-1];
                A[j-1] = tmp;
                
                j -= 1;
            }
        }
    }
    return "YES";
}


int main() {
    vector<int> A = {3, 1, 2};

    string ans = larrysArray(A);

    return 0;
}