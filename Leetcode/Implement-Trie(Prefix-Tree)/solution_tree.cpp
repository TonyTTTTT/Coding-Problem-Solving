#include <string>
using namespace std;


class MyTreeNode {
public:
    bool isWord;
    MyTreeNode* childs[26];

    MyTreeNode() {
        isWord = false;
        for (auto& child : childs) child = nullptr;
    }
};


class Trie {
private:
    MyTreeNode* root;
public:
    Trie() {
        root = new MyTreeNode();
    }
    
    void insert(string word) {
        MyTreeNode* tmp = root;

        for (auto c : word) {
            int i = c - 'a';

            if (!tmp->childs[i]) {
                tmp->childs[i] = new MyTreeNode();
            }
            tmp = tmp->childs[i];
        }

        tmp->isWord = true;
    }
    
    bool search(string word, bool isPrefix=false) {
        MyTreeNode* tmp = root;

        for (auto c : word) {
            int i = c - 'a';

            if (!tmp->childs[i]) return false;
            tmp = tmp->childs[i];
        }

        if (isPrefix) return true;

        return tmp->isWord;
    }
    
    bool startsWith(string prefix) {
        return search(prefix, true);
    }
};

int main() {
    Trie* obj = new Trie();
    obj->insert("pig");
    bool param_2 = obj->search("pi");
    bool param_3 = obj->startsWith("pi");

    __asm("nop");
}