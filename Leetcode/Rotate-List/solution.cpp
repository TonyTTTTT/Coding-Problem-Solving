#include <iostream>
#include "../ListNode.h"
using namespace std;

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || k == 0) return head;
        
        int listLen = 0;
        ListNode* current = head;

        while (current != nullptr) {
            listLen++;
            current = current->next;
        }

        k = k % listLen;
        
        if (k==0) return head;

        current = head;
        ListNode* prev;

        for (int i=0; i<listLen-k; i++) {
            prev = current;
            current = current->next;
        }
        prev->next = nullptr;
        
        ListNode* ans = current;

        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = head;


        return ans;
    }
};

int main() {
    Solution solution;
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    int k = 12;

    ListNode* ans = solution.rotateRight(head, k);
    __asm("nop");
}