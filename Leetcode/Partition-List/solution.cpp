#include "../ListNode.h"
using namespace std;

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head) return head;

        ListNode* dummy = new ListNode(0, head);

        ListNode* cur = dummy;

        while (cur->next && cur->next->val < x) cur = cur->next;
        ListNode* parPoint = cur;

        while (cur && cur->next) {
            if (cur->next->val < x)   {
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                tmp->next = parPoint->next;
                parPoint->next = tmp;
                parPoint = parPoint->next;
            } else cur = cur->next;
        }

        return dummy->next;
    }
};

int main() {
    Solution solution;
    // ListNode* head = new ListNode(1, new ListNode(4, new ListNode(3, new ListNode(2, new ListNode(5, new ListNode(2))))));
    ListNode* head = new ListNode(2, new ListNode(1));
    int x = 2;

    ListNode* ans = solution.partition(head, x);
}