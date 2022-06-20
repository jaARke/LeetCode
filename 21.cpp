struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = nullptr;
        ListNode* curr = nullptr;
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                if (!head) {
                    head = list1;
                    curr = list1;
                }
                else {
                    curr->next = list1;
                    curr = curr->next;
                }
                list1 = list1->next;
            }
            else {
                if (!head) {
                    head = list2;
                    curr = list2;
                }
                else {
                    curr->next = list2;
                    curr = curr->next;
                }
                list2 = list2->next;
            }
        }
        while (list1) {
            if (!head) {
                head = list1;
                curr = list1;
            }
            else {
                curr->next = list1;
                curr = curr->next;
            }
            list1 = list1->next;
        }
        while (list2) {
            if (!head) {
                head = list2;
                curr = list2;
            }
            else {
                curr->next = list2;
                curr = curr->next;
            }
            list2 = list2->next;
        }
        return head;
    }
};