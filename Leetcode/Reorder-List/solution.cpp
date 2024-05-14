#include <iostream>
#include "../ListNode.h"

class Solution {
public:
    void reorderList(MyListNode* head) {
        MyListNode* tail = head;
        MyListNode* current = head;
        MyListNode* sub_tail;

        while (tail->next != nullptr) {
            sub_tail = tail;
            tail = tail->next;
        }

        while (current->next != tail and current != tail) {
            tail->next = current->next;
            current->next = tail;
            current = current->next->next;
            sub_tail->next = nullptr;

            tail = head;
            while (tail->next != nullptr) {
                sub_tail = tail;
                tail = tail->next;
            }
        }
    }
};

int main() {
    Solution solution;
    MyListNode* head = new MyListNode(1, new MyListNode(2, new MyListNode(3, new MyListNode(4, new MyListNode(5)))));
    
    solution.reorderList(head);
    __asm("nop");
}