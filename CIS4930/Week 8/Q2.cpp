#include <iostream>
#include <map>
#include <unordered_set>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    map<int, int> m;
    for (int i = 1; i <= n; i++) {
        cin >> m[i];
    }
    for (int i = 1; i <= n; i++) {
        unordered_set<int> s;
        s.insert(i);
        int q = m[i];
        while (s.find(q) == s.end()) {
            s.insert(q);
            q = m[q];
        }
        cout << q << " ";
    }
    return 0;
}