#include "../ListNode.h"
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head) return head;

        ListNode* curr = head;
        int size = 0;

        while (curr) {
            size++;
            curr = curr->next;
        }

        ListNode *dummy = new ListNode(0, head);
        int step;
        for (step=1; step<size; step<<=1) {
            curr = dummy->next;
            ListNode* last = dummy;
            while (curr) {
                ListNode* l1 = curr;
                ListNode* l2 = split(curr, step);

                curr = split(l2, step);

                ListNode* merged = merge(l1, l2);

                last->next = merged;
                while (merged->next) merged = merged->next;
                merged->next = curr;
                last = merged;
            }
        }

        return dummy->next;
    }

    ListNode* split(ListNode* head, int step) {
        ListNode* prev;

        for (int i=0; i<step; i++) {
            if (!head) break;
            prev = head;
            head = head->next;
        }

        if (prev) prev->next = nullptr;

        return head;
    }


    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        
        ListNode* curr = dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }

        if (l1) curr->next = l1;
        if (l2) curr->next = l2;

        return dummy->next;
    }
};

int main() {
    Solution solution;
    ListNode* head = new ListNode(-1, new ListNode(5, new ListNode(3, new ListNode(4, new ListNode(0)))));

    ListNode* ans = solution.sortList(head);

    __asm("nop");
}