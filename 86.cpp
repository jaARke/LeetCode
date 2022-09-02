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
    ListNode* partition(ListNode* head, int x) {
        if (!head) {
            return nullptr;
        }
        vector<ListNode*> v1, v2;
        while (head) {
            if (head->val < x) {
                v1.push_back(head);
            }
            else {
                v2.push_back(head);
            }
            ListNode* temp = head->next;
            head->next = nullptr;
            head = temp;
        }
        ListNode* prev = nullptr;
        for (int i = 0; i < v1.size(); i++) {
            if (prev) {
                prev->next = v1[i];
            }
            prev = v1[i];
        }
        for (int i = 0; i < v2.size(); i++) {
            if (prev) {
                prev->next = v2[i];
            }
            prev = v2[i];
        }
        return (v1.size() == 0 ? v2[0] : v1[0]);
    }
};