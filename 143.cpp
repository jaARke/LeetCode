#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        stack<ListNode*> nodes;
        ListNode* next = head;
        while (head->next != nullptr) {
            nodes.push(head);
            head = head->next;
        }
        int n = nodes.size() / 2;
        for (int i = 0; i < n / 2; i++) {
            ListNode* temp = next->next;
            next->next = nodes.top();
            nodes.top()->next = temp;
            next = temp;
            nodes.pop();
        }
        next->next = nullptr;
    }
};