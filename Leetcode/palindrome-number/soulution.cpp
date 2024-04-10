#include<string>
#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    bool isPalindrome(int x) {
        vector<int> split;
        if (x < 0) {
            return false;
        } else if (x == 0) {
            return true;
        }
        while (x!=0) {
            split.push_back(x%10);
            x /= 10;
        }
        while (split.size() > 1 and split.front() == split.back()) {
            split.pop_back();
            split.erase(split.begin());
        }
        if (split.size() == 1 or split.empty()) {
            return true;
        } else {
            return false;
        }
    }
};


int main() {
    Solution solution;

    bool ans = solution.isPalindrome(11);
    if (ans) {
        cout<<"true"<<endl;
    } else {
        cout<<"fasle"<<endl;
    }
    return 0;
}