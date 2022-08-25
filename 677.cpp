#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class MapSum {
private:
    unordered_map<string, int> actual;
    unordered_map<string, int> resids;
public:
    MapSum() = default;
    
    void insert(string key, int val) {
        int diff;
        if (actual.find(key) != actual.end()) {
            diff = val - actual[key];
        }
        else {
            diff = val;
        }
        for (int i = 1; i <= key.length(); i++) {
            resids[key.substr(0, i)] += diff;
        }
        actual[key] = val;
    }
    
    int sum(string prefix) {
        return resids[prefix];
    }
};


int main() {
    MapSum ms;
    ms.insert("apple", 3);
    cout << ms.sum("ap") << endl;
    ms.insert("app", 2);
    cout << ms.sum("ap") << endl;
    return 0;
}