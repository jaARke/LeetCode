using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
 * Another question (like 287) that uses Floyd's Tortoise & Hare. This time the question uses a linked list, but the
 * process is generally the same. For more details, see the link provided in 287.cpp
 */

class Solution {
public:
    ListNode* detectCycle(ListNode *head) {
        ListNode* tortoise = head;
        ListNode* hare = head;
        bool flag = false;
        while (hare && hare->next) {
            tortoise = tortoise->next;
            hare = hare->next->next;
            if (tortoise == hare) { // Cycle found -> the tortoise and the hare have met
                flag = true;
                break;
            }
        }
        if (!flag) {
            return nullptr;
        }
        // Find the start of the cycle by resetting tortoise and finding where they meet going at the same speed.
        tortoise = head;
        while (tortoise != hare) {
            tortoise = tortoise->next;
            hare = hare->next;
        }
        return hare;
    }
};