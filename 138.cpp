#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        unordered_map<Node*, Node*> m;
        Node* ans = nullptr;

        Node* prev = new Node(head->val);
        m[head] = prev;
        if (head->random != nullptr) {
            if (m.find(head->random) == m.end()) {
                prev->random = new Node(head->random->val);
                m[head->random] = prev->random;
            }
            else {
                prev->random = m[head->random];
            }
        }
        head = head->next;
        ans = prev;

        while (head != nullptr) {
            if (m.find(head) == m.end()) {
                prev->next = new Node(head->val);
                m[head] = prev->next;
            }
            else {
                prev->next = m[head];
            }
            prev = prev->next;
            if (head->random != nullptr) {
                if (m.find(head->random) == m.end()) {
                    prev->random = new Node(head->random->val);
                    m[head->random] = prev->random;
                }
                else {
                    prev->random = m[head->random];
                }
            }
            head = head->next;
        }
        return ans;
    }
};