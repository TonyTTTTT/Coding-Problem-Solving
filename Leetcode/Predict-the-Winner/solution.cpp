#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> mem;

    int calculateScore(vector<int>& nums, int left, int right) {
        if (left == right) return nums[left];

        if (mem[left*nums.size()+right] != 0) return mem[left*nums.size()+right];

        mem[left*nums.size()+right] = max(nums[left] - calculateScore(nums, left+1, right), nums[right] - calculateScore(nums, left, right-1));

        return mem[left*nums.size()+right];
    }
    
    bool predictTheWinner(vector<int>& nums) {
        mem = vector<int>(nums.size() * nums.size(), 0);
        int score = calculateScore(nums, 0, nums.size()-1);
        
        return score >= 0;
    }
};


int main() {
    Solution solution;
    vector<int> v = {1000,1000,1000,0,0,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000};

    bool ans = solution.predictTheWinner(v);
    __asm("nop");
}