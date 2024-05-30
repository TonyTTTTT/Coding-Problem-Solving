using namespace std;

class Solution {
public:
    __UINT32_TYPE__ reverseBits(__UINT32_TYPE__ n) {
        __UINT32_TYPE__ ans;

        ans = (n & 0xffff0000) >> 16 | (n & 0x0000ffff) << 16;
        ans = (ans & 0xff00ff00) >> 8 | (ans & 0x00ff00ff) << 8;
        ans = (ans & 0xf0f0f0f0) >> 4 | (ans & 0x0f0f0f0f) << 4;
        ans = (ans & 0xcccccccc) >> 2 | (ans & 0x33333333) << 2;
        ans = (ans & 0xaaaaaaaa) >> 1 | (ans & 0x55555555) << 1;

        return ans;
    }
};

int main() {
    Solution solution;
    __UINT32_TYPE__ n = 4294967293;

    __UINT32_TYPE__ ans = solution.reverseBits(n);
}