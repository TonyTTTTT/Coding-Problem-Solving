// you can use includes, for example:
// #include <algorithm>
#include <vector>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> sum;
    int q, r, tmp;
    unsigned int i,j;

    for (i=0; i<A.size(); i++) {
        // printf("%d\n", A[i]);
        q = A[i];
        tmp = 0;
        while(q / 10 > 0) {
            r = q % 10;
            tmp  = tmp + r;
            q = q / 10;
        }
        tmp = tmp + q;
        sum.push_back(tmp);
        // printf("tmp: %d\n", tmp);
        // for (j=0; j<sum.size(); j++)
        //     printf("%d ", sum[j]);
        // printf("\n");
    }

    int ans = -1;

    for (i=0; i<A.size(); i++) {
        for (j=i+1; j<A.size(); j++) {
            if (sum[i] == sum[j] && A[i] + A[j] > ans) {
                ans = A[i] + A[j];
                // printf("i: %d, j: %d\n", i, j);
                // printf("sum[i]: %d, sum[j]: %d\n", sum[i], sum[j]);
            }
        }
    }
    return ans;
}
