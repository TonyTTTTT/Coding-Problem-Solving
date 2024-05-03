#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <string.h>
using namespace std;

char t[1001];           // 原字串
char s[1001 * 2];       // 穿插特殊字元之後的t
int z[1001 * 2], L, R;  // 源自Gusfield's Algorithm

// 由a往左、由b往右，對稱地作字元比對。
class Solution {
public:
    int extend(int a, int b, int N)
    {
        int i = 0;
        while (a-i>=0 && b+i<N && s[a-i] == s[b+i]) i++;
        return i;
    }

    string longestPalindrome(string t)
    {
        int N = t.size();

        // t穿插特殊字元，存放到s。
        // （實際上不會這麼做，都是細算索引值。）
        memset(s, '.', N*2+1);
        for (int i=0; i<N; ++i) s[i*2+1] = t[i];

        N = N*2+1;
    //  s[N] = '\0';    // 可做可不做

        // Manacher's Algorithm
        z[0] = 1;
        L = R = 0;
        for (int i=1; i<N; ++i)
        {
            int ii = L - (i - L);   // i的映射位置
            int n = R + 1 - i;

            if (i > R)
            {
                z[i] = extend(i, i, N);
                L = i;
                R = i + z[i] - 1;
            }
            else if (z[ii] == n)
            {
                z[i] = n + extend(i-n, i+n, N);
                L = i;
                R = i + z[i] - 1;
            }
            else
            {
                // why min?
                // 因為超出R的話就選n
                // 沒超出R的話就選z[ii]
                // 且這邊沒有z[ii] == n 之可能
                z[i] = min(z[ii], n);
            }
        }

        // 尋找最長迴文子字串的長度。
        int n = 0, p = 0;
        for (int i=0; i<N; ++i)
            if (z[i] > n)
                n = z[p = i];

        // 記得去掉特殊字元。
        // cout << "最長迴文子字串的長度是" << (n-1) / 2 <<endl;

        // 印出最長迴文子字串，記得別印特殊字元。
        string ans = "";
        for (int i=p-z[p]+1; i<=p+z[p]-1; ++i)
            if (i & 1)
                ans.push_back(s[i]);
                // cout << s[i];
        return ans;
    }
};

int main() {
    Solution solution;
    string ans = solution.longestPalindrome("aab");
    cout<<"ANS: "<<ans<<endl;
    return 0;
}