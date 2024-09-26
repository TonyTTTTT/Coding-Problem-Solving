template<typename T>
 struct ListNode {
     T val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(T x) : val(x), next(nullptr) {}
     ListNode(T x, ListNode *next) : val(x), next(next) {}
 };