#include <bits/stdc++.h>

using namespace std;

int speed_up = []{
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    return 0;
}();

class LRUCache {
private:
    int cap;
    unordered_map<int, int> cache;
    unordered_map<int, int> freqs;  // Number of times each key appears in the deque
    deque<int> d;   // Stream of recently used keys (grows from the front, shrinks from the back)

public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (cache.find(key) != end(cache)) {
            d.push_front(key);
            freqs[key]++;
            return cache[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cache.size() == cap && cache.find(key) == end(cache)) {
            while (--freqs[d.back()] > 0) d.pop_back();

            cache.erase(d.back());
            d.pop_back();
        }
        d.push_front(key);
        freqs[key]++;
        cache[key] = value;
    }
};