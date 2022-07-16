#include <iostream>
#include <vector>
#include <set>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    
    set<int> available;
    vector<int> conq(n + 1);
    for (int i = 1; i <= n; i++) {
        available.insert(i);
        conq[i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int l, r, w;
        cin >> l >> r >> w;
        auto iter = available.lower_bound(l);
        while (iter != available.end() && *iter <= r) {
            if (*iter != w) {
                conq[*iter] = w;
                auto nextEl = next(iter);
                available.erase(iter);
                iter = nextEl;
            }
            else {
                iter++;
            }

        }
    }
    for (int i = 1; i <= n; i++) {
        cout << conq[i] << ' ';
    }
    return 0;
}