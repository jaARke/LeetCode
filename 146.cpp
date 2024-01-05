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
    int capacity;
    unordered_map<int, list<pair<int, int>>::iterator> cache;
    list<pair<int, int>> evicList;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        auto iter = cache.find(key);
        if (iter == end(cache)) return -1;

        int val = iter->second->second;

        evicList.erase(iter->second);
        evicList.push_front({key, val});

        cache.erase(key);
        cache[key] = evicList.begin();

        return val;
    }
    
    void put(int key, int value) {
        auto iter = cache.find(key);

        if (iter != end(cache)) {
            evicList.erase(iter->second);
            cache.erase(key);
        }
        evicList.push_front({key, value});
        cache[key] = evicList.begin();

        if (cache.size() > capacity) {
            cache.erase(evicList.back().first);
            evicList.pop_back();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

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
    LRUCache c(10);
    c.put(7, 28);
    c.put(7 ,1);
    c.put(8, 15);
    c.get(6);
    c.put(10, 27);
    c.put(8, 10);
    c.get(8);
    c.put(6, 29);
    c.put(1, 9);
    c.get(6);
    c.put(10, 7);
    c.get(1);
    c.get(2);
    c.get(13);
    c.put(8, 30);
    c.put(1, 5);
    c.get(1);
    c.put(13 ,2);
    c.get(12);
    return 0;
}