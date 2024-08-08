#include <unordered_map>

struct MyListNode {
    int val;
    int key;
    MyListNode* next;
    MyListNode* prev;
    MyListNode(int k, int v) : key(k), val(v), next(nullptr), prev(nullptr) {};
    MyListNode(int k, int v, MyListNode* n, MyListNode* p) : key(k), val(v), next(n), prev(p) {};
};

class LRUCache {
    std::unordered_map<int, MyListNode*> k2n;
    MyListNode* head;
    MyListNode* tail;
    int capacity;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new MyListNode(-1, -1, tail, nullptr);
        tail = new MyListNode(-1, -1, nullptr, head);
    }
    
    int get(int key) {
        if (!k2n.count(key)) return -1;
        updateInList(key);

        return k2n[key]->val;
    }

    void put(int key, int value) {
        if (k2n.count(key)) {
            updateInList(key);
            k2n[key]->val = value;
        } else {
            MyListNode* newNode = new MyListNode(key, value);
            k2n[key] = newNode;

            addBeforeTail(newNode);

            if (capacity == 0) {
                k2n.erase(head->next->key);
                head->next = head->next->next;
                head->next->prev = head;
            } else capacity--;
        }
    }

    void updateInList(int key) {
        MyListNode* target = k2n[key];

        if (target != tail->prev) {
            target->prev->next = target->next;
            target->next->prev = target->prev;

            addBeforeTail(target);
        }
    }

    void addBeforeTail(MyListNode* target) {
        tail->prev->next = target;
        target->prev = tail->prev;
        tail->prev = target;
    }
};

int main() {
    int capacity = 2;
    int res = 0;

    LRUCache* obj = new LRUCache(capacity);
    obj->put(1, 1);
    obj->put(2, 2);
    res = obj->get(1);
    obj->put(3, 3);
    res = obj->get(2);
    obj->put(4, 4);
    res = obj->get(1);
    res = obj->get(3);
    res = obj->get(4);

    __asm("nop");
}