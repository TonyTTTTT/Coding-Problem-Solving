#include <iostream>
using namespace std;


 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *prev=NULL, *current=NULL, *tmp=NULL;
        if (head != NULL) {
            if (head->next != NULL) {
                prev = head;
                current = head->next;

                prev->next = current->next;
                current->next = prev;
                head = current;

                current = prev->next;

                while (current !=NULL) {
                    if (current->next != NULL) {
                        prev->next = current->next;
                        current->next = current->next->next;
                        prev->next->next = current;

                        prev = current;
                        current = current->next;
                    } else {
                        break;
                    }
                }
            }
        }
        return head;
    }
};

int main() {
    Solution solution;
    ListNode a(1), b(2), c(3), d(4), e(1);
    a.next = &b;
    b.next = &c;
    // c.next = &d;

    ListNode* ans = solution.swapPairs(&a);

    return 0;
}