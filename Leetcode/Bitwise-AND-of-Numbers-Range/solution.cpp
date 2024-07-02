class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        long long range = __int128_t(right) - __int128_t(left) + 1;
        int ans = 0;
        int leftmost = 0;
        int rightmost = 0;
        
        for (long long i=2; i<=right; i*=2) leftmost++;
        for (long long i=1; i<range; i*=2) rightmost++;
        
        for (int i=rightmost; i<leftmost; i++) {
            bool setBit = true;
            for (long long cur=left; cur<=right; cur++) {
                if ((cur >> i & 1) == 0) {
                    setBit = false;
                    break;
                }
            }
            if (setBit) ans |= 1<<i;
        }

        if (left >= 1<<leftmost) ans |= 1<<leftmost;

        return ans;
    }
};

int main() {
    Solution solution;
    int left = 2;
    int right = 2;

    int ans = solution.rangeBitwiseAnd(left, right);
}