#include <vector>
#include <algorithm>
// #include <iostream>
using namespace std;

int formingMagicSquare(vector<vector<int>> s) {
    vector<int> corner1 = {2, 4, 8, 6};
    vector<int> mid1 = {9, 3, 1, 7};

    vector<int> corner2 = {2, 6, 8, 4};
    vector<int> mid2 = {7, 1, 3, 9};

    vector<int> curCorner = {s[0][0], s[0][2], s[2][2], s[2][0]};
    vector<int> curMid = {s[0][1], s[1][2], s[2][1], s[1][0]};

    int ans = INT_MAX;
    int tmp1, tmp2;
    for (int i=0; i<4; i++) {
        tmp1 = 0;
        tmp2 = 0;
        int idx = 0;
        int j=i;
        
        do {
            tmp1 += abs(curCorner[idx]-corner1[j]);
            tmp1 += abs(curMid[idx] - mid1[j]);

            tmp2 += abs(curCorner[idx] - corner2[j]);
            tmp2 += abs(curMid[idx] - mid2[j]);

            idx++;
            j = (j+1)%4;
        } while (j != i);
        
        ans = min(ans, tmp1);
        ans = min(ans, tmp2);
    }

    ans += abs(s[1][1] - 5);

    return ans;
}

int main() {
    vector<vector<int>> s = {
        {6,1,2},{7,2,6},{5,6,2}
    };

    int ans = formingMagicSquare(s);
}