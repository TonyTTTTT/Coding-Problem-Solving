// you can use includes, for example:
#include <algorithm>
#include <vector>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> v;
    unsigned int i;
    unsigned int next, nnext;

    v.push_back(1);
    for (i=0; i<500000; i++) {
        next = v[i]*2;
        nnext = v[i]*3;
        v.push_back(next);
        v.push_back(nnext);
        // exist1 = false;
        // exist2 = false;
        // for (j=0; j<v.size(); j++) {
        //     if (v[j] == next)
        //         exist1 = true;
        //     if (v[j] == nnext)
        //         exist2 = true;
        // }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    // for (i=0; i<v.size(); i++)
    //     printf("%d ", v[i]);
    // printf("\n");
    // printf("v.size(): %d\n", v.size());
    
    return v[N];
}
