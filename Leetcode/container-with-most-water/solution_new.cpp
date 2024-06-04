#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int ans = 0;
        int curSize;

        while (l < r) {
            curSize = (r-l) * min(height[l], height[r]);
            if (curSize > ans) ans = curSize;

            if (height[l] < height[r]) l++;
            else r--;
        }

        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> height = {1,8,6,2,5,4,8,3,7};

    int ans = solution.maxArea(height);
}