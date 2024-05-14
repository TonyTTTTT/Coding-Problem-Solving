#include <unordered_map>
#include <vector>
using namespace std;

 struct ListNode {
     int val;
     int key;
     ListNode *next;
     ListNode() : val(0), key(0), next(nullptr) {}
     ListNode(int x, int y) : val(x), key(y), next(nullptr) {}
     ListNode(int x, int y, ListNode *next) : val(x), key(y), next(next) {}
 };


class LRUCache {
private:
    int capacity;
    int size;
    ListNode* head;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = nullptr;
        size = 0;
    }
    
    int get(int key) {
        ListNode* current = head;
        ListNode* prev = head;

        while (current != nullptr) {
            if (current->key == key) {
                if (current != head) {
                    prev->next = current->next;
                    current->next = head;
                    head = current;
                }

                return current->val;
            }
            prev = current;
            current = current->next;
        }

        return -1;
    }
    
    void put(int key, int value) {
        if (size == capacity) {
            if (capacity == 1) {
                head = nullptr;
            } else { //capacity > 1
                ListNode* current = head;
                ListNode* prev;

                while (current->next != nullptr) {
                    if (current->key == key) {
                        current->val = value;
                        
                        if (current != head) {
                            prev->next = current->next;
                            current->next = head;
                            head = current;
                        }

                        return;
                    }
                    prev = current;
                    current = current->next;
                }
                prev->next = nullptr;
            }
        } else {
            size++;
        }

        ListNode* newNode = new ListNode(value, key, head);
        head = newNode;
    }
};

int main() {
    int capacity = 3;
    int key = 5;
    int value = 18;

    LRUCache* obj = new LRUCache(capacity);
    int res = obj->get(5);
    obj->put(5, 18);
    res = obj->get(5);
    obj->put(1, 12);
    obj->put(5, 6);
    res = obj->get(1);
    obj->put(3, 56);
    res = obj->get(5);
    obj->put(4, 8);
    res = obj->get(1);
    res = obj->get(4);


    __asm("nop");
}