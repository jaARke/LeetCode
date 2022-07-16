#include <vector>
#include <iostream>

using namespace std;

void runDFS(vector<vector<int>>& graph, vector<int>& visited, bool& cyclFlag, int u, int visNum) {
    if (visited[u] != 0) {  // This node has already been visited -> check for a cycle and return
        if (visited[u] != visNum) {
            cyclFlag = true;
        }
        return;
    }
    visited[u] = visNum;
    if (visNum == 1) {
        visNum = 2;
    }
    else {
        visNum = 1;
    }
    for (auto& x : graph[u]) {
        runDFS(graph, visited, cyclFlag, x, visNum);
    }
}


int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> graph(n + 1);
    vector<int> visited(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    bool cyclFlag = false;
    int result = 0;
    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            runDFS(graph, visited, cyclFlag, i, 1);
            result++;
        }
    }
    if (!cyclFlag) { // Compensate for a cycle
        result++;
    }
    result--;   // Offset
    cout << result << endl;
    return 0;
}
