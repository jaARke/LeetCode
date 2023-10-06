#include <bits/stdc++.h>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> s;
        s.insert(head);
        while (head && s.find(head->next) == s.end()) {
            s.insert(head->next);
            head = head->next;
        }
        return head ? head->next : head;
    }
};