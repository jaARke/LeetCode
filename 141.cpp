#include <algorithm>
#include <cmath>

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
    bool hasCycle(ListNode *head) {
        while (head != nullptr) {
            if (head->val == INT32_MAX) {
                return true;
            }
            head->val = INT32_MAX;
            head = head->next;
        }
        return false;
    }
};