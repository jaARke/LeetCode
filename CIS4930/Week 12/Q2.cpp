#include <iostream>
#include <vector>

using namespace std;

/*
Check if the graph is bipartite using graph coloring, then compare the colors to see which edges come before which. A lower-colored vertex indicates it comes before a higher-colored vertex.
*/

void checkBipartite(int u, int color, bool& flag, vector<vector<int>>& adjList, vector<int>& visited) {
    visited[u] = color;
    
    int newColor;
    if (color == 1) {
        newColor = 2;
    }
    else {
        newColor = 1;
    }

    for (auto x : adjList[u]) {
        if (visited[x] == 0) {
            checkBipartite(x, newColor, flag, adjList, visited);
        }
        else if (visited[x] != newColor) {
            flag = false;
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjList(n + 1);
    vector<pair<int, int>> edgeList;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
        edgeList.push_back(make_pair(u, v));
    }

    vector<int> visited (n + 1, 0);
    bool flag = true;
    checkBipartite(1, 1, flag, adjList, visited);

    if (flag) {
        cout << "YES" << endl;
        for (int i = 0; i < m; i++) {
            if (visited[edgeList[i].first] < visited[edgeList[i].second]) {
                cout << 1;
            }
            else {
                cout << 0;
            }
        }
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}