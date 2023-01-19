#include <bits/stdc++.h>

using namespace std;

class RandomizedSet {
private:
    unordered_map<int, int> m;
    vector<int> v;

public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if (m.find(val) == m.end()) {
            v.push_back(val);
            m[val] = v.size() - 1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if (m.find(val) != m.end()) {
            int lastEl = v.back();
            swap(v[m[val]], v.back());
            swap(m[lastEl], m[val]);
            v.pop_back();
            m.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return v[rand() % v.size()];
    }
};


int main() {
    RandomizedSet rs;
    rs.insert(1);
    rs.remove(2);
    rs.insert(2);
    cout << rs.getRandom() << endl;
    rs.remove(1);
    rs.insert(2);
    cout << rs.getRandom() << endl;
    return 0;
}
