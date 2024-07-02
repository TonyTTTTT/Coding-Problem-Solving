class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int cnt = 0;

        while(left != right) {
            left >>= 1;
            right >>= 1;
            cnt++;
        }

        return left << cnt;
    }
};

int main() {
    Solution solution;
    int left = 2;
    int right = 2;

    int ans = solution.rangeBitwiseAnd(left, right);
}