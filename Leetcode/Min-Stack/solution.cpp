#include "../ListNode.h"
#include <vector>
using namespace std;

struct MyListNode {
    int val;
    int min;
    MyListNode* next;

    MyListNode(int x, int y) : val(x), min(y), next(nullptr) {};
    MyListNode(int x, int y, MyListNode* n) : val(x), min(y), next(n) {};
};


class MinStack {
    MyListNode* head;
public:
    MinStack() {
        head = nullptr;
    }
    
    void push(int val) {
        if (!head) {
            head = new MyListNode(val, val);
        } else {
            head = new MyListNode(val, min(val, head->min), head);
        }
    }
    
    void pop() {
        head = head->next;
    }
    
    int top() {
        return head->val;
    }
    
    int getMin() {
        return head->min;
    }
};



int main() {
    MinStack* obj = new MinStack();
    obj->push(-2);obj->push(0);obj->push(-3);
    int param_1 = obj->getMin();
    obj->pop();
    int param_2 = obj->top();
    int param_3 = obj->getMin();

    return 0;
}
