#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <functional>

void printAfterApply(std::vector<int>& nums, std::function<int(int)> func) {
    for (auto num : nums) {
        std::cout << func(num) <<std::endl;
    }
}


int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 3};

    auto sum = std::accumulate(begin(nums), end(nums),
                                0,
                                [](auto sum, auto value)                           
                                {
                                    if (value > 4) return sum + value;
                                    else return sum;
                                });

    int offset = 3;
    printAfterApply(nums, [offset](auto value){ return value + offset; });
    
    return 0;
}