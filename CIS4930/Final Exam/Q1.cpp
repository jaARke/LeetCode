#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void runDFS(vector<vector<int>>& adjList, vector<bool>& vis, int u, int& count) {
    vis[u] = true;
    for (auto& x : adjList[u]) {
        if (!vis[x]) {
            count++;
            runDFS(adjList, vis, x, count);
        }
    }
    return;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> adjList(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    vector<bool> vis(n + 1, false);
    int result = 0;
    int idx = 1;
    for (int i = 0; i < k; i++) {
        int u;
        cin >> u;
        if (!vis[u]) {
            int count = 1;
            runDFS(adjList, vis, u, count);
            if (count > result) {
                idx = u;
                result = count;
            }
        }
    }
    cout << idx << '\n';
    return 0;
}
