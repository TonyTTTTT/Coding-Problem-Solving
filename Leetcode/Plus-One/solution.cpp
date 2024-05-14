#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int idx = digits.size() - 1;
        int carry = 0;

        do {
            digits[idx]++;
            if (digits[idx] == 10) {
                digits[idx] = 0;
                carry = 1;
            } else {
                carry = 0;
            }
            idx--;
        } while (idx >= 0 && carry);

        if (carry) {
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};

int main() {
    Solution solution;
    vector<int> digits = {9, 9, 9, 9};

    vector<int> ans = solution.plusOne(digits);
}