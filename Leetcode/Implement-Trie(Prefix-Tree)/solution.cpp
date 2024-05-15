#include <iostream>
#include <unordered_set>
using namespace std;

class Trie {
private:
    unordered_set<string> dict;
    unordered_set<string> swDict;
public:
    Trie() {
        dict = {};
        swDict = {};
    }
    
    void insert(string word) {
        dict.insert(word);

        string tmp = "";
        for(auto c : word) {
            tmp += c;
            swDict.insert(tmp);
        }
    }
    
    bool search(string word) {
        return dict.count(word);
    }
    
    bool startsWith(string prefix) {
        return swDict.count(prefix);
    }
};

int main() {
    Trie* obj = new Trie();
    obj->insert("pig");
    bool param_2 = obj->search("pi");
    bool param_3 = obj->startsWith("pi");

    __asm("nop");
}