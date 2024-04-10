#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool is_even(int n) {
        return n%2 == 0;
    }

    int lastRemaining(int n) {
        if (n==1) return 1;

        int first = 2;
        int step = 2;
        int remain = n/2;
        int turn = 0;

        int ans = ifFirstIsLast(first, step, remain, n, turn);

        return ans;
    }

    int ifFirstIsLast(int first, int step, int remain, int n, int turn) {
        while (first + step <= n) {
            if (turn == 0) {
                if (!is_even(remain)) {
                    first += step;
                }
            } else {
                first += step;
            }
            step *= 2;
            turn = (turn+1) % 2;
            remain /= 2;
        }

        return first;
    }

    // int ifFirstIsLast(int first, int step, int remain, int n, int turn) {
    //     if (first + step > n) return first;

    //     if (turn == 0) {
    //         if (!is_even(remain)) {
    //             first += step;
    //         }
    //     } else {
    //         first += step;
    //     }
    //     step *= 2;
    //     turn = (turn+1) % 2;
    //     remain /= 2;

    //     return ifFirstIsLast(first, step, remain, n, turn);
    // }

    // int iterateElimiate(vector<int> arr) {
    //     while (arr.size() != 1) {
    //         for (int i=1, j=0; i<arr.size(); i+=2, j++) {
    //             arr[j] = arr[i];
    //         }
    //         arr = vector<int>(arr.begin(), arr.begin() + (arr.size()/2));
    //         reverse(arr.begin(), arr.end());
    //     }

    //     return arr[0];
    // }

    // int recurseEliminate(vector<int> arr) {
    //     int ans;
    //     for (int i=1, j=0; i<arr.size(); i+=2, j++) {
    //         arr[j] = arr[i];
    //     }

    //     if (arr.size() == 1) {
    //         return arr[0];
    //     } else {
    //         arr = vector<int>(arr.begin(), arr.begin() + (arr.size()/2));
    //         reverse(arr.begin(), arr.end());
    //         ans = recurseEliminate(arr);
    //     }

    //     return ans;
    // }
};

int main() {
    Solution solution;
    int ans = solution.lastRemaining(9);
    __asm("nop");
}