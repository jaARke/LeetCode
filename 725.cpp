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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> res(k);
        int count = 0;

        ListNode* left = head;
        while (head) {
            head = head->next;
            count++;
        }

        int dist = count / k;
        int rem = count % k;

        for (int i = 0; i < k; i++) {
            ListNode* right = nullptr;
            for (int j = 0; j < dist; j++) {
                if (!right) right = left;
                else right = right->next;
            }
            if (rem > 0) {
                if (!right) right = left;
                else right = right->next;
                rem--;
            }

            ListNode* temp = nullptr;
            if (right) {
                temp = right->next;
                right->next = nullptr;
            }
            res[i] = left;
            left = temp;
        }
        return res;
    }
};

int main() {

}