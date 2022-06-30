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
        if (!head) {
            return nullptr;
        }
        unordered_map<Node*, Node*> m;
        m[nullptr] = nullptr;
        Node* newHead = new Node(head->val);
        m[head] = newHead;
        Node* curr = newHead;
        while (head != nullptr) {
            if (m.find(head->random) != m.end()) {
                curr->random = m[head->random];
            }
            else {
                curr->random = new Node(head->random->val);
                m[head->random] = curr->random;
            }
            if (head->next) {
                if (m.find(head->next) != m.end()) {
                    curr->next = m[head->next];
                }
                else {
                    curr->next = new Node(head->next->val);
                    m[head->next] = curr->next;
                }
            }
            else {
                curr->next = nullptr;
            }
            head = head->next;
            curr = curr->next;
        }
        return newHead;
    }
};

/*
 * Basically the exact same solution; done on different dates.
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
 */