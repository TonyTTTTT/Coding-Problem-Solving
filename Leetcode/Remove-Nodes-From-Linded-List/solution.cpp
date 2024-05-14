#include <iostream>
#include "../ListNode.h"
using namespace std;

class Solution {
public:
    MyListNode* removeNodes(MyListNode* head) {
        if (head->next == nullptr) return head;

        head->next = removeNodes(head->next);

        return head->val < head->next->val ? head->next : head;
    }
};

int main() {
    Solution solution;
    MyListNode* head = new MyListNode(5, new MyListNode(2, new MyListNode(13, new MyListNode(3, new MyListNode(8)))));

    MyListNode* ans = solution.removeNodes(head);
    __asm("nop");
}