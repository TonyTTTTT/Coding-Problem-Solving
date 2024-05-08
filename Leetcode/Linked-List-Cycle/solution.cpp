#include <iostream>
#include "../ListNode.h"
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow) return true;
        }

        return false;
    }
};

int main() {
    Solution solution;
    ListNode* head = new ListNode(3, new ListNode(2, new ListNode(0, new ListNode(-4))));
    head->next->next->next->next = head->next;

    bool ans = solution.hasCycle(head);
    __asm("nop");
}