#include <map>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

/*
Implementation of Edmonds-Karp maximum flow algorithm with an edge list. Not sure if it would have been faster to use an adjacency matrix; question said n was small so I figured this was best.
*/


bool isPathToSink(vector<vector<int>>& graph, vector<int>& prevNodes, int source, int target) {
    vector<bool> seen(graph.size(), false);
    queue<int> q;

    q.push(source);
    seen[source] = true;
    prevNodes[source] = -1;

    while (!q.empty()) {
        int qi = q.front();
        q.pop();

        for (int i = 0; i < graph[qi].size(); i++) {
            if (graph[qi][i] > 0 && !seen[i]) { // Not seen AND has a viable edge
                if (i == target) {    // Target node found
                    prevNodes[i] = qi;
                    return true;
                }
                seen[i] = true;
                prevNodes[i] = qi;
                q.push(i);
            }
        }
    }
    return false;   // Target node not found in a bfs from source
}

int edmondsKarp(vector<vector<int>>& graph, int source, int target) {
    vector<int> prevNodes(graph.size());
    int result = 0;

    while (isPathToSink(graph, prevNodes, source, target)) {
        int localResult = INT32_MAX;
        int currNode = target;
        while (currNode != source) {  // Traverse through parents and find minimum edge weight in this path
            int prev = prevNodes[currNode];
            localResult = min(localResult, graph[prev][currNode]);
            currNode = prev;
        }
        currNode = target;
        // Update the graph with new path (must reverse it)
        while (currNode != source) {
            int prev = prevNodes[currNode];
            graph[prev][currNode] -= localResult;
            graph[currNode][prev] += localResult;
            currNode = prev;
        }
        result += localResult;
    }
    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums;
    vector<vector<int>> graph(n, vector<int>(n, 0));
    int minIdx = 0, maxIdx = 0;
    for (int i = 0; i < n; i++) {
        int currRoom;
        cin >> currRoom;
        if (nums.size() > 0 && currRoom > nums[maxIdx]) {
            maxIdx = i;
        }
        if (nums.size() > 0 && currRoom < nums[minIdx]) {
            minIdx = i;
        }
        for (int j = 0; j < nums.size(); j++) {
            int gcd = __gcd(currRoom, nums[j]);
            if (gcd > 1) {
                graph[i][j] = gcd;
                graph[j][i] = gcd;
            }
        }
        nums.push_back(currRoom);
    }
    cout << edmondsKarp(graph, minIdx, maxIdx) << endl;
    return 0;
}