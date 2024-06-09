#include "../TreeNode.h"
#include <queue>
#include <stack>
using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode* n) : val(x), next(n) {};
};

ListNode* inOrder(TreeNode* root, ListNode* head) {
    if (!root) return nullptr;
    
    
    ListNode* cur = inOrder(root->left, head);
    
    if (!cur) cur = head;
    cur->next= new ListNode(root->val);
    cur = cur->next;
    head = cur;

    cur = inOrder(root->right, cur);

    if (!cur) cur = head;

    return cur;
}

class BSTIterator {
private:
    stack<TreeNode*> s;

    void pushLeft(TreeNode* root) {
        while (root) {
            s.push(root);
            root = root->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }
    
    int next() {
        TreeNode* curLess = s.top(); s.pop();
        if (curLess->right) {
            pushLeft(curLess->right);
        }

        return curLess->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};


int main() {
    TreeNode* root = new TreeNode(7, new TreeNode(3), new TreeNode(15, new TreeNode(9), new TreeNode(20)));

    BSTIterator* obj = new BSTIterator(root);
    int param_1 = obj->next();
    bool param_2 = obj->hasNext();

    __asm("nop");
}