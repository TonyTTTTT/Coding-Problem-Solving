#include "../ListNode.h"
#include <iostream>
using namespace std;

class Solution {
    int recursive(ListNode* cur, ListNode** twin, int idx, const int n) {
        if (idx == n/2) {
            *twin = cur->next;
            return cur->val + (*twin)->val;
        }

        int res = recursive(cur->next, twin, idx+1, n);

        *twin = (*twin)->next;
        res = max(res, cur->val + (*twin)->val);

        return res;
    }
public:
    int pairSum(ListNode* head) {
        int n = 0;
        ListNode* tmp = head;
        while(tmp) {
            n++;
            tmp = tmp->next;
        }

        tmp = head;
        int ans = recursive(head, &tmp, 1, n);

        return ans;
    }
};

int main() {
    Solution sol;
    ListNode* head = new ListNode(4, new ListNode(2, new ListNode(2, new ListNode(3))));

    int ans = sol.pairSum(head);

    return 0;
}