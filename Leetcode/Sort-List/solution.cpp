#include "../ListNode.h"
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head) return head;
        
        vector<pair<int, ListNode*>> v;
        
        while (head != nullptr) {
            v.push_back({head->val, head});
            head = head->next;
        }
        sort(v.begin(), v.end());

        for (int i=0; i<v.size()-1; i++) {
            v[i].second->next = v[i+1].second;
        }

        v[v.size()-1].second->next = nullptr;

        return v[0].second;
    }
};

int main() {
    Solution solution;
    ListNode* head = new ListNode(-1, new ListNode(5, new ListNode(3, new ListNode(4, new ListNode(0)))));

    ListNode* ans = solution.sortList(head);
}