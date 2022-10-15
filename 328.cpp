struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head) {
            return nullptr;
        }
        ListNode* oddHead = head;
        ListNode* evenHead = head->next;
        ListNode* oddTail = oddHead;
        ListNode* evenTail = evenHead;
        ListNode* oddIter = oddTail;
        ListNode* evenIter = evenTail;
        while (oddIter && evenIter && oddIter->next && evenIter->next) {
            oddIter = oddIter->next->next;
            evenIter = evenIter->next->next;
            oddTail->next = oddIter;
            evenTail->next = evenIter;
            oddTail = oddTail->next;
            evenTail = evenTail->next;
        }
        oddTail->next = evenHead;
        return oddHead;
    }
};