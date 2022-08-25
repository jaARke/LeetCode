#include <vector>

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* origHead = head;
        int i = 0;
        ListNode* before = nullptr;
        ListNode* after = nullptr;
        vector<ListNode*> v;
        while (head) {
            if (i == left - 2) {
                before = head;
            }
            if (i == right) {
                after = head;
            }
            if (i >= left - 1 && i <= right - 1) {
                v.push_back(head);
            }
            i++;
            head = head->next;
        }
        if (before == nullptr) {
            origHead = v.back();
        }
        else {
            before->next = v.back();
        }
        for (int j = v.size() - 1; j > 0; j--) {
            v[j]->next = v[j - 1];
        }
        v.front()->next = after;
        return origHead;
    }
};