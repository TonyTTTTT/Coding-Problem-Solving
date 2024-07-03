#include <unordered_map>
#include <stdlib.h>
#include <vector>
#include <time.h>
using namespace std;

class RandomizedSet {
    unordered_map<int, int> v2i;
    vector<int> nums;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (v2i.count(val)) return false;

        nums.push_back(val);
        v2i[val] = nums.size()-1;

        return true;
    }
    
    bool remove(int val) {
        if (!v2i.count(val)) return false;

        nums[v2i[val]] = nums.back();
        v2i[nums.back()] = v2i[val];
        nums.pop_back();
        v2i.erase(val);

        return true;
    }
    
    int getRandom() {
        int idx = rand();
        return nums[idx % nums.size()];
    }
};


int main() {
    RandomizedSet* obj = new RandomizedSet();
    int val = 4;
    bool param_1 = obj->insert(4);
    bool param_2 = obj->insert(4);
    bool param_3 = obj->insert(8);
    bool param_4 = obj->remove(5);
    int param_5 = obj->getRandom();

    return 0;
}