#include <iostream>
#include "../ListNode.h"
using namespace std;

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        if (head->next == nullptr) return head;

        head->next = removeNodes(head->next);

        return head->val < head->next->val ? head->next : head;
    }
};

int main() {
    Solution solution;
    ListNode* head = new ListNode(5, new ListNode(2, new ListNode(13, new ListNode(3, new ListNode(8)))));

    ListNode* ans = solution.removeNodes(head);
    __asm("nop");
}