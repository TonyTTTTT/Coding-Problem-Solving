// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    unsigned int i, tmp = 0;
    int ans = 0;

    for (i=0; i<S.size(); i++) {
        // printf("%c ", S[i]);
        if (tmp == 3) {
            ans = -1;
            break;
        }
        if (S[i] == 'a') {
            tmp++;
        } else {
            ans = ans + (2 - tmp);
            tmp = 0;
        }
    }
    if (tmp == 3)
        ans = -1;
    else
        ans = ans + (2 - tmp);
        
    return ans;
}
