#include "../ListNode.h"
#include <algorithm>
using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        int carry = 0;

        while (l1 || l2 || carry) {
            carry += (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            cur->next = new ListNode(carry % 10);
            cur = cur->next;
            carry /= 10;

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        return dummy->next;
    }
};

int main() {
    Solution solution;
    ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(9)));
    ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4, new ListNode(9))));

    ListNode* ans = solution.addTwoNumbers(l1, l2);

    return 0;
}