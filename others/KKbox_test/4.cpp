// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    unsigned int i, j, k;
    int sum;
    int ans = -1;
    bool continue_flag = false;

    // for escape extreme condition
    if (A.size() >= 100000) {
        for (i=0; i<A.size(); i++) {
            if (A[i] != 0) {
                continue_flag = true;
            }
        }
    } else {
        continue_flag = true;
    }
    
    if (continue_flag) {
        ans = 0;
        for (i=0; i<A.size(); i++) {
            for (j=i; j<A.size(); j++) {
                sum = 0;
                for (k=i; k<=j; k++) {
                    sum = sum + A[k];
                }
                if (sum == 0) {
                    ans++;
                    // printf("i: %d, j: %d\n", i, j);
                }
                if (ans>1000000000) {
                    ans = -1;
                    break;
                }
            }
        }
    }
    return ans;
}
