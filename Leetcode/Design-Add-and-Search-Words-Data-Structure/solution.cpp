#include <iostream>
using namespace std;

struct MyTreeNode {
	MyTreeNode* childs[26] = {nullptr};
    bool isEnd = false;
};

class WordDictionary {
    MyTreeNode* root;
public:
    WordDictionary() {
        root = new MyTreeNode();
    }
    
    void addWord(string word) {
        MyTreeNode* cur = root;
        for (char c : word) {
            if (!cur->childs[c-'a']) {
                cur->childs[c-'a'] = new MyTreeNode();
            }

            cur = cur->childs[c-'a'];
        }

        cur->isEnd = true;
    }
        
    bool search(string word) {
        return search(word, root, 0);
    }

    bool search(string word, MyTreeNode* curNode, int curIdx) {
        for (int i = curIdx; i<word.size(); i++) {
            if (word[i] == '.') {
                for (auto child : curNode->childs) {
                    if (child && search(word, child, i+1)) return true;
                }
                return false;
            } else if (curNode->childs[word[i] - 'a']) {
                curNode = curNode->childs[word[i] - 'a'];
            } else return false;		
        }

        return curNode->isEnd;
   }
};

int main() {
    WordDictionary* obj = new WordDictionary();
    obj->addWord("bad");
    obj->addWord("dad");
    obj->addWord("mad");
    bool param_1 = obj->search("pad");
    bool param_2 = obj->search("bad");
    bool param_3 = obj->search(".ad");
    bool param_4 = obj->search("b..");

    return 0;
}