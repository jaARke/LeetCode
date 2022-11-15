#include <bits/stdc++.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast) {
            if (!fast->next) {
                slow->next = slow->next->next;
                return head;
            }
            else {
                fast = fast->next->next;
                if (!fast) {
                    slow->next = slow->next->next;
                    return head;
                }
                slow = slow->next;
            }
        }
        return nullptr;
    }
};