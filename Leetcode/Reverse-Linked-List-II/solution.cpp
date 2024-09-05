#include "../ListNode.h"
using namespace std;

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;

        ListNode* dummy = new ListNode(0, head);

        ListNode* prev = dummy;
        ListNode *start, *tmp;

        for (int i=1; i<left; i++) prev = prev->next;
        start = prev->next;

        for (int i=0; i<right-left; i++) {
            tmp = prev->next;
            prev->next = start->next;
            start->next = start->next->next;
            prev->next->next = tmp; 
        }

        return dummy->next;
    }
};

void revers(ListNode *head,ListNode **newhead){
    if(head -> next == nullptr){
        *newhead = head;
        return ;
    }
    revers(head -> next , newhead);

    head->next->next = head;
    head->next = nullptr;
    return ;
}

int main() {
    Solution solution;
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));

    // ListNode* ans = solution.reverseBetween(head, 1, 5);

    ListNode* newhead;
    revers(head, &newhead);

    return 0;
}