#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespace std;

int runBFS(unordered_map<int, vector<int>>& adjList, int n, int m) {
    /*
    Find shortest path between the first row and the last using a BFS and a dp array. The dp array holds the minimum edges required to travel to a given
    row or column. At the end of the algorithm, the distance to row n will be the answer.
    */
    vector<int> dp(n + m + 1, INT32_MAX);
    unordered_set<int> visited;
    queue<int> q;

    q.push(1);
    visited.insert(1);
    dp[1] = 0;
    while (!q.empty()) {
        int qi = q.front();
        q.pop();
        for (int i = 0; i < adjList[qi].size(); i++) {
            int ai = adjList[qi][i];
            dp[ai] = min(dp[ai], dp[qi] + 1);
            if (visited.find(ai) == visited.end()) {
                q.push(ai);
                visited.insert(ai);
            }
        }
    }
    return (dp[n] == INT32_MAX ? -1 : dp[n]);
}

int main() {
    int n, m;
    cin >> n >> m;

    unordered_map<int, vector<int>> adjList;
    for (int i = 1; i <= n; i++) {  // i corresponds to rows
        for (int j = 1; j <= m; j++) {  // j corresponds to columns
            char c;
            cin >> c;
            if (c == '#') {
                // Make an undirected edge from the i'th row to the j'th column (the j'th column is enumerated as j + n)
                adjList[i].push_back(j + n);
                adjList[j + n].push_back(i);
            }
        }
    }
    cout << runBFS(adjList, n, m) << endl;
    return 0;
}