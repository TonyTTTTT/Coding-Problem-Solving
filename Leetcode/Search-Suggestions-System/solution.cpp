#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
    vector<string> binSearch(vector<string>& products, string prefix) {
        int l = 0, r = products.size() - 1;

        while (l < r) {
            int mid = (l + r) / 2;
            if (prefix.compare(products[mid]) <= 0) r = mid;
            else l = mid + 1;
        }

        vector<string> res;
        for (int i=0; i<3; i++) {
            if (l+i < products.size() && products[l+i].find(prefix) != string::npos) res.push_back(products[l+i]);
        }

        return res;
    }
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());

        vector<vector<string>> ans;
        string prefix = "";
        for (char c : searchWord) {
            prefix += c;

            vector<string> tmp = binSearch(products, prefix);
            ans.push_back(tmp);
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<string> products = {"mobile","mouse","moneypot","monitor","mousepad"};
    string searchWord = "mouse";

    vector<vector<string>> ans = sol.suggestedProducts(products, searchWord);

    return 0;
}