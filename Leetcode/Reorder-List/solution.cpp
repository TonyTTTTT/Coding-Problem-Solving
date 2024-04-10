#include <iostream>
#include "../ListNode.h"

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* tail = head;
        ListNode* current = head;
        ListNode* sub_tail;

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
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    
    solution.reorderList(head);
    __asm("nop");
}