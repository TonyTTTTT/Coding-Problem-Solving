#include "../ListNode.h"
#include <iostream>

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = addTwoNumbers(l1, l2, 0);
        return result;
    }

    int check_carry(ListNode* n) {
        if (n->val >= 10) {
            n->val %= 10;
            return 1;
        }

        return 0;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int carry) {
        ListNode* current = new ListNode();

        if (l1==nullptr and l2==nullptr) {
            if (carry != 0) {
                current->val = carry;
            } else {
                return nullptr;
            }
        } else if (l1==nullptr) {
            current->val = l2->val + carry;
            carry = check_carry(current);
            if (carry) {
                current->next = addTwoNumbers(nullptr, l2->next, carry);
            } else {
                current->next = l2->next;
            }
        } else if (l2==nullptr) {
            current->val = l1->val + carry;
            carry = check_carry(current);
            if (carry) {
                current->next = addTwoNumbers(l1->next, nullptr, carry);
            } else {
                current->next = l1->next;
            }
        } else {
            current->val = l1->val + l2->val + carry;
            carry = check_carry(current);
            current->next = addTwoNumbers(l1->next, l2->next, carry);
        }


        return current;
    }
};

int main() {
    Solution solution;
    ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));

    ListNode* ans = solution.addTwoNumbers(l1, l2);
    __asm("nop");
    
}