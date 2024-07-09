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

class AVLTree {
    node* root;
    
    void adjustHt(node* cur) {
        int leftHt = cur->left ? cur->left->ht : -1;
        int rightHt = cur->right ? cur->right->ht : -1;

        cur->ht = max(leftHt, rightHt) + 1;
    }

    node* leftRotate(node* cur) {
        node* tmp = cur->right;
        cur->right = tmp->left;
        tmp->left = cur;

        adjustHt(cur);
        adjustHt(tmp);

        return tmp;
    }

    node* rightRotate(node* cur) {
        node* tmp = cur->left;
        cur->left = tmp->right;
        tmp->right = cur;

        adjustHt(cur);
        adjustHt(tmp);

        return tmp;
    }

    node* insert(int val, node* cur) {
        if (!cur) {
            node* newNode = new node();
            newNode->val = val;
            newNode->ht = 0;
            return newNode;
        }
        
        if (val > cur->val) {
            cur->right = insert(val, cur->right);
            cur->ht = max(cur->ht, cur->right->ht + 1);
        } else  {
            cur->left = insert(val, cur->left);
            cur->ht = max(cur->ht, cur->left->ht + 1);
        }

        int leftHt = cur->left ? cur->left->ht : -1;
        int rightHt = cur->right ? cur->right->ht : -1;
        int htDiff = leftHt - rightHt;
        bool rootChange = false;

        if (abs(htDiff) > 1) {
            if (cur == this->root) rootChange = true;

            if (htDiff > 0) { // left-X case
                leftHt = cur->left->left ? cur->left->left->ht : -1;
                rightHt = cur->left->right ? cur->left->right->ht : -1;
                if (leftHt < rightHt) { // left-right case
                    cur->left = leftRotate(cur->left);
                }
                cur = rightRotate(cur);
            } else { // right-X case
                leftHt = cur->right->left ? cur->right->left->ht : -1;
                rightHt = cur->right->right ? cur->right->right->ht : -1;
                if (leftHt > rightHt) { // right-left case
                    cur->right = rightRotate(cur->right);
                }
                cur = leftRotate(cur);
            }
            
        }

        this->root = cur;
        return cur;
    }

public:
    AVLTree(node* root) {
        this->root = root;
    } 

    void insert(int val) {
        insert(val, this->root);
    }

    node* getRoot() {
        return this->root;
    }
};

node* insert(node* root,int val) {
    AVLTree* avltree = new AVLTree(root);
    avltree->insert(val);
    
    return avltree->getRoot();
}



int main() {
    // node* root = new node(14, 3, new node(10, 1, new node(7, 0), new node(12, 0)), new node(25, 2, new node(21 ,1, new node(16, 0), new node(23, 0)), new node (26, 1, nullptr, new node(30, 0))));

    // root = insert(root, 19);
    node *root = new node(17, 3, new node(6, 2, nullptr, new node(10, 1, nullptr, new node(16, 0))), new node(18, 1, nullptr, new node(22, 0)));
    root = insert(root, 21);

    return 0;
}