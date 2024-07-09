#include <iostream>
using namespace std;

typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
    
    node(): val(0), ht(0), left(nullptr), right(nullptr) {};
    node(int x, int y) : val(x), ht(y), left(nullptr), right(nullptr) {};
    node(int x, int y, node* l, node* r) : val(x), ht(y), left(l), right(r) {};
} node;


node* adjust(node* root, node* violateRoot) {
    int leftHt = violateRoot->left ? violateRoot->left->ht : -1;
    int rightHt = violateRoot->right ? violateRoot->right->ht : -1;
    node* mid = leftHt > rightHt ? violateRoot->left : violateRoot->right;

    leftHt = mid->left ? mid->left->ht : -1;
    rightHt = mid->right ? mid->right->ht : -1;
    node* third = leftHt > rightHt ? mid->left : mid->right;

    if (third->val > mid->val && mid->val < violateRoot->val) {
        violateRoot->left = third;
        mid->right = third->left;
        third->left = mid;

        swap(mid, third);
    } else if (third->val < mid->val && mid->val > violateRoot->val) {
        violateRoot->right = third;
        mid->left = third->right;
        third->right = mid;

        swap(mid, third);
    }

    if (mid->val < violateRoot->val) {
        violateRoot->left = mid->right;
        mid->right = violateRoot;

        swap(violateRoot, mid);
    } else if (mid->val > violateRoot->val) {
        violateRoot->right = mid->left;
        mid->left = violateRoot;

        swap(violateRoot, mid);
    }

    return violateRoot;
}

int adjustHt(node* root) {
    if (!root) return -1;

    root->ht = 1 + max(adjustHt(root->left), adjustHt(root->right));

    return root->ht;
}

node* findViolateRoot(node* root) {
    if (!root) return nullptr;

    node* leftViolateRoot = findViolateRoot(root->left);
    if (leftViolateRoot) return leftViolateRoot;

    node* rightViolateRoot = findViolateRoot(root->right);
    if (rightViolateRoot) return rightViolateRoot;

    int leftHt = root->left ? root->left->ht : -1;
    int rightHt = root->right ? root->right->ht : -1;

    return abs(leftHt - rightHt) > 1 ? root : nullptr;
}

node* insert(node* root,int val)
{
	node *prev=nullptr, *cur = root;
    
    while (cur) {
        prev = cur;
        if (val < cur->val) cur = cur->left;
        else cur = cur->right;
    }
    node* newNode = new node();
    newNode->val = val;
    if (val < prev->val) {
        prev->left = newNode;
    }
    else prev->right = newNode;

    adjustHt(root);

    node* violateRoot = findViolateRoot(root);

    while(violateRoot) {
        node* violateRootParent = nullptr;
        cur = root;
        while (cur != violateRoot) {
            violateRootParent =cur;
            if (violateRoot->val > cur->val) cur = cur->right;
            else cur = cur->left;
        } 

        violateRoot = adjust(root, violateRoot);

        if (!violateRootParent) root = violateRoot;
        else {
            if (violateRoot->val < violateRootParent->val) violateRootParent->left = violateRoot;
            else violateRootParent->right = violateRoot;
        }
        
        adjustHt(root);

        violateRoot = findViolateRoot(root);        
    }

    return root;
}

int main() {
    node* root = new node(14, 3, new node(10, 1, new node(7, 0), new node(12, 0)), new node(25, 2, new node(21 ,1, new node(16, 0), new node(23, 0)), new node (26, 1, nullptr, new node(30, 0))));

    root = insert(root, 19);

    return 0;
}