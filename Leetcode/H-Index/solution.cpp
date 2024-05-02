#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        vector<int> bucket(citations.size()+1, 0);
        int ans;

        for (int i=0; i<citations.size(); i++) {
            if (citations[i] < bucket.size())
                bucket[citations[i]]++;
            else
                bucket[bucket.size()-1]++;
        }

        int total = 0;
        for (int i=bucket.size()-1; i>=0; i--) {
            total += bucket[i];

            if (total >= i) {
                ans = i;
                break;
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> citations{3,0,0,1,5};

    int ans = solution.hIndex(citations);
    __asm("nop");
}