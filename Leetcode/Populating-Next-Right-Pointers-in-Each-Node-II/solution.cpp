#include "../NextTreeNode.h"
#include <queue>
using namespace std;


class Solution {
public:
    Node* connect(Node* root) {
        Node* first = root;
        Node *curr = nullptr, *prev = nullptr;

        while (first) {
            curr = first;
            first = nullptr;
            while (curr) {
                if (curr->left) {
                    if (prev) {
                        prev->next = curr->left;
                    } else {
                        first = curr->left;
                    }
                    prev = curr->left;
                }

                if (curr->right) {
                    if (prev) {
                        prev->next = curr->right;
                    } else {
                        first = curr->right;
                    }
                    prev = curr->right;
                }
                curr = curr->next;
            }
            prev = nullptr;
        }

        return root;
    }
};

int main() {
    Solution solution;
    Node* root = new Node(1, new Node(2, new Node(4), new Node(5), nullptr), new Node(3, nullptr, new Node(7), nullptr), nullptr);

    Node* ans = solution.connect(root);
}