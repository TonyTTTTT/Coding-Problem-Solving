#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
    static bool cmp(const string& a, const string& b) {
        auto itra = a.begin();
        auto itrb = b.begin();
        
        while (itra != a.end() && itrb != b.end() && *itra == *itrb) {
            itra++;
            itrb++;
        }
        
        if (itra == a.end() && itrb == b.end()) return *a.begin() > *b.begin();
        if (itra == a.end()) return cmp(a, string(itrb, b.end()));
        if (itrb == b.end()) return cmp(string(itra, a.end()), b);

        return *itra > *itrb;
    }
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> numsStr(n);

        for (int i=0; i<n; i++) {
            numsStr[i] = to_string(nums[i]);
        }

        sort(numsStr.begin(), numsStr.end(), cmp);

        string ans = "";

        for (auto s : numsStr) ans += s;
        
        if (ans[0] == '0') ans = "0";

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    // vector<int> nums = {0, 0};

    string ans = sol.largestNumber(nums);

    return 0;
}