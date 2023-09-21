#include <bits/stdc++.h>

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
    ListNode* partition(ListNode* head, int x) {
        ListNode* lessHead = nullptr;
        ListNode* greaterHead = nullptr;
        ListNode* lessTail = nullptr;
        ListNode* greaterTail = nullptr;

        while (head) {
            ListNode* save = head->next;
            if (head->val < x) {
                if (lessHead) {
                    lessTail->next = head;
                    lessTail = lessTail->next;
                }
                else {
                    lessHead = head;
                    lessTail = head;
                }
                lessTail->next = nullptr;
            }
            else {
                if (greaterHead) {
                    greaterTail->next = head;
                    greaterTail = greaterTail->next;
                    greaterTail->next = nullptr;
                }
                else {
                    greaterHead = head;
                    greaterTail = head;
                }
                greaterTail->next = nullptr;
            }
            head = save;
        }
        if (lessHead) {
            lessTail->next = greaterHead;
            return lessHead;
        }
        return greaterHead;
    }
};

int main() {
    Solution s;
    ListNode* head = new ListNode(1, new ListNode(4, new ListNode(3, new ListNode(2, new ListNode(5, new ListNode(2))))));
    int x = 3;
    auto* res = s.partition(head, x);
    cout << "Done!" << endl;
    return 0;
}