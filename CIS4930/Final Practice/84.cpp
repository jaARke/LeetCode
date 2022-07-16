#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjList (n + m + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c;
            cin >> c;
            if (c == '#') {
                adjList[i].push_back(n + j);
                adjList[n + j].push_back(i);
            }
        }
    }
    vector<bool> vis(n + m + 1, false);
    vector<int> dists(n + m + 1, INT32_MAX);
    queue<int> q;
    vis[1] = true;
    dists[1] = 0;
    q.push(1);

    while (!q.empty()) {
        int qi = q.front();
        q.pop();
        vis[qi] = false;
        for (auto& x : adjList[qi]) {
            if (dists[x] > dists[qi] + 1) {
                dists[x] = dists[qi] + 1;
                q.push(x);
                vis[x] = true;
            }
        }
    }
    cout << (dists[n] != INT32_MAX ? dists[n] : -1) << '\n';
    return 0;
}