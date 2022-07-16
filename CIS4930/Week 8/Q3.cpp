#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
    int v, e;
    cin >> v >> e;
    unordered_map<int, unordered_set<int>> m;
    for (int i = 0; i < e; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        m[v1].insert(v2);
        m[v2].insert(v1);
    }
    bool flag = true;
    int count = 0;
    while (flag) {
        unordered_set<int> visited;
        flag = false;
        auto iter = m.begin();
        while (iter != m.end()) {
            if (iter->second.size() == 0) {
                auto iter1 = next(iter);
                m.erase(iter);
                iter = iter1;
                continue;
            }
            if (iter->second.size() == 1 && visited.find(iter->first) == visited.end()) {
                m[*(iter->second.begin())].erase(iter->first);
                visited.insert(*(iter->second.begin()));
                auto iter1 = next(iter);
                m.erase(iter);
                iter = iter1;
                flag = true;
            }
            else {
                iter++;
            }
        }
        if (flag) {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}