#include "../ListNode_temp.h"
#include <vector>
#include <string>
#include <iostream>

class Solution {
public:
    ListNode<char> * reverseWord(ListNode<char> *head) {
        if (!head) return head;

        ListNode<char> *dummy = new ListNode(' ', head);
        ListNode<char> *start = dummy;
        ListNode<char> *cur = dummy;
        ListNode<char> *prev;

        while (cur) {
            prev = nullptr;
            cur = cur->next;

            while (cur && cur->val != ' ') {
                ListNode<char> *tmp = cur->next;
                cur->next = prev;
                prev = cur;
                cur = tmp;
            }
            start->next->next = cur;
            start->next = prev;
            start = cur;
        }

        return dummy->next;
    }
};

int main() {
    Solution sol;
    // ListNode<char> *head = new ListNode('c', new ListNode('a', new ListNode('t', new ListNode(' ', new ListNode('d', new ListNode('o', new ListNode('g')))))));
    // ListNode<char> *head = nullptr;

    ListNode<char> *head = new ListNode('g');

    std::string s = "once upon the time, there is a dog and a cat get along well!";

    ListNode<char> *dummy = new ListNode<char>();
    ListNode<char> *tmp = dummy;

    for (char c : s) {
        tmp->next = new ListNode(c);
        tmp = tmp->next;
    }

    ListNode<char> *ans = sol.reverseWord(dummy->next);

    while (ans) {
        std::cout << ans->val;       
        ans = ans->next;
    }
    std::cout << std::endl;

    return 0;
}