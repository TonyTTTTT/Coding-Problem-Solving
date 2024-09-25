#include <vector>
#include <queue>
using namespace std;

class SmallestInfiniteSet {
    vector<bool> exist = vector<bool>(1001, true);
    priority_queue<int, vector<int>, greater<int>> pq;
public:
    SmallestInfiniteSet() {
        // vector<int> tmp(1001);
        for (int i=1; i<=1000; i++) pq.push(i);

        // pq = priority_queue<int>(tmp.begin(), tmp.end());
    }
    
    int popSmallest() {
        int smallest = pq.top();
        pq.pop();
        exist[smallest] = false;

        return smallest;
    }
    
    void addBack(int num) {
        if (!exist[num]) {
            pq.push(num);
            exist[num] = true;
        }
    }
};

int main() {
    SmallestInfiniteSet* obj = new SmallestInfiniteSet();
    int param_1;

    obj->addBack(2);
    param_1 = obj->popSmallest();
    param_1 = obj->popSmallest();
    param_1 = obj->popSmallest();
    obj->addBack(1);
    param_1 = obj->popSmallest();
    param_1 = obj->popSmallest();
    param_1 = obj->popSmallest();

    return 0;
}