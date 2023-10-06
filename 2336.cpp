#include <bits/stdc++.h>

using namespace std;

/*
class SmallestInfiniteSet {
private:
    set<int> s;
public:
    SmallestInfiniteSet() {
        s.insert(1);
    }
    
    int popSmallest() {
        int res = *s.begin();
        s.erase(res);
        if (s.empty()) s.insert(res + 1);
        return res;
    }
    
    void addBack(int num) {
        if (num < *s.rbegin()) {
            s.insert(num);
        }
    }
};
*/

class SmallestInfiniteSet {
private:
    vector<bool> v = vector<bool>(1001, true);
    int pos = 1;
public:    
    int popSmallest() {
        int res = pos;
        v[pos] = false;
        while (!v[++pos]);
        return res;
    }
    
    void addBack(int num) {
        v[num] = true;
        pos = min(pos, num);
    }
};