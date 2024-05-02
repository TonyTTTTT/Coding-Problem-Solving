#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int idx1 = 0, idx2 = numbers.size()-1;

        while (numbers[idx1]+numbers[idx2] != target) {
            if (numbers[idx1]+numbers[idx2] < target) {
                idx1++;
            } else {
                idx2--;
            }
        }

        return vector<int>{idx1+1, idx2+1};
    }
};

int main() {
    Solution solution;
    vector<int> numbers{2,3,4};
    int target = 6;

    vector<int> ans = solution.twoSum(numbers, target);
}