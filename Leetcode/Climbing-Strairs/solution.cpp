class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        else if (n == 2) return 2;

        int a = 1, b = 2, ans;

        for (int i=3; i<=n; i++) {
            ans = a + b;
            a = b;
            b = ans;
        }

        return ans;
    }
};

int main() {
    Solution solution;
    int n = 5;

    int ans = solution.climbStairs(n);
}