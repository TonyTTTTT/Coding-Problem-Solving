#include <iostream>
#include "../ListNode.h"
#include <stack>
using namespace std;

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* current = head;
        ListNode* tail;
        stack<ListNode*> s;

        while (current != nullptr) {
            s.push(current);
            current = current->next;
        }

        current = head;
        tail = s.top();
        s.pop();
        while (current!=tail and current->next!=tail) {
            tail->next = nullptr;
            tail->next = current->next;
            current->next = tail;
            current = current->next->next;
            tail = s.top();
            s.pop();
        }
        tail->next = nullptr;    
    }
};

int main() {
    Solution solution;
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
    
    solution.reorderList(head);
    __asm("nop");
}