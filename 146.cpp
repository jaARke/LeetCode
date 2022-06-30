#include <unordered_map>
#include <queue>
#include <vector>
#include <list>
#include <iostream>

using namespace std;

/*
 * This is a solution using STL structures and iterators. Same as below, but more concise.
 */

class LRUCache {
private:
    unordered_map<int, pair<int, list<int>::iterator>> m;
    list<int> l;
    int capacity;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (m.find(key) == m.end()) {
            return -1;
        }
        l.erase(m[key].second);
        l.push_front(key);
        m[key].second = l.begin();
        return m[key].first;
    }

    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            m[key].first = value;
            l.erase(m[key].second);
            l.push_front(key);
            m[key].second = l.begin();
        }
        else {
            if (m.size() == capacity) {
                m.erase(l.back());
                l.pop_back();
            }
            l.push_front(key);
            m[key] = make_pair(value, l.begin());
        }
    }
};

/*
 * The following is a homemade solution using a doubly-linked list.
struct Node {
    int val;
    Node* prev = nullptr;
    Node* next = nullptr;
    Node(int val, Node* prev = nullptr) {
        this->val = val;
        this->prev = prev;
    }
};
class LRUCache {
private:
    int capacity;
    Node* head;
    Node* tail;
    unordered_map<int, pair<int, Node*>> m;

    void moveNodeBack(Node* n) {
        if (n != tail) {
            if (n == head) {
                n->next->prev = nullptr;
                head = n->next;
            }
            else {
                n->prev->next = n->next;
                n->next->prev = n->prev;
            }
            tail->next = n;
            n->prev = tail;
            tail = tail->next;
        }
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = nullptr;
        tail = nullptr;
    }

    int get(int key) {
        if (m.find(key) == m.end()) {
            return -1;
        }
        moveNodeBack(m[key].second);
        return m[key].first;
    }

    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            moveNodeBack(m[key].second);
            m[key].first = value;
        }
        else {
            if (m.size() == capacity) {
                m.erase(head->val);
                if (head->next) {
                    head->next->prev = nullptr;
                }
                head = head->next;
            }
            if (!tail || !head) {
                tail = new Node(key);
                head = tail;
            }
            else {
                tail->next = new Node(key, tail);
                tail = tail->next;
            }
            m[key] = make_pair(value, tail);
        }
    }
};
 */

int main() {
    LRUCache c(1);
    c.put(4, 9);
    c.put(9,7);
    c.put(4,8);
    c.put(6, 5);
    c.put(1,3);
    c.put(27, 54);
    cout << c.get(4) << endl;
}