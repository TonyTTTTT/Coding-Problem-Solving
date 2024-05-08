#include <iostream>
#include <unordered_map>
#include <vector>
#include "../ListNodeRandom.h"
using namespace std;

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* iter = head;

        while (iter != nullptr) {
            Node* next = iter->next;
            Node* copy = new Node(iter->val);

            iter->next = copy;
            copy->next = next;
            iter = next;
        }

        iter = head;
        while (iter != nullptr) {
            if (iter->random != nullptr) iter->next->random = iter->random->next;
            iter = iter->next->next;
        }

        Node* newHead = new Node(0);
        Node* newIter = newHead;
        iter = head;

        while (iter != nullptr) {
            newIter->next = iter->next;
            newIter = newIter->next;

            iter->next = iter->next->next;
            iter = iter->next;
        }

        return newHead->next;
    }
};

int main() {
    Solution solution;
    Node *head = new Node(7), *a = new Node(13), *b = new Node(11), *c = new Node(10), *d = new Node(1);
    head->next = a; a->next = b; b->next = c; c->next = d;

    a->random = head; b->random = d; c->random = b; d->random = head;

    Node* ans = solution.copyRandomList(head);
}