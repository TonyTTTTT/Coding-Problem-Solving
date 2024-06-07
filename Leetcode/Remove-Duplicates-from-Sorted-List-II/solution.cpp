#include "../ListNode.h"
using namespace std;

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        ListNode* cur = prev->next;

        while (cur) {
            ListNode* numFirst = cur;

            while (cur->next && cur->next->val == cur->val) {
                cur = cur->next;
            }

            if (prev->next == cur) prev = cur;
            else prev->next = cur->next;

            cur = cur->next;
        }

        return dummy->next;
    }
};

int main() {
    Solution solution;
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(3, new ListNode(4, new ListNode(4, new ListNode(5)))))));
    ListNode* head2 = nullptr;

    ListNode* ans = solution.deleteDuplicates(head);
}