#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

/*
Implementation of Edmonds-Karp maximum flow algorithm with an adjacency matrix. Not sure if it would have been faster to use an adjacency list; question said n was small so I figured this was best.
Tried in two ways -> returning bool in findMinEdge for whether or not target can be found in bfs, and returning int for the minEdge weight. I thought the second way would be faster, but the first 
had a runtime of almost 1/3 the second. I'm guessing this could be due to the large number of min() calls? Anyways, I think this structure is more concise so I kept it.
*/

int findMinEdge(vector<vector<int>>& graph, vector<int>& prevNodes, int source, int target) {
    vector<bool> seen(graph.size(), false);
    queue<int> q;
    int minEdge = INT32_MAX;

    q.push(source);
    seen[source] = true;
    prevNodes[source] = -1;
    while (!q.empty()) {
        int qi = q.front();
        q.pop();
        for (int i = 0; i < graph[qi].size(); i++) {
            if (graph[qi][i] > 0 && !seen[i]) { // Not seen AND has a viable edge
                minEdge = min(minEdge, graph[qi][i]);
                if (i == target) {    // Target node found
                    prevNodes[i] = qi;
                    return minEdge;
                }
                seen[i] = true;
                prevNodes[i] = qi;
                q.push(i);
            }
        }
    }
    return 0;   // Target node not found in a bfs from source
}

int edmondsKarp(vector<vector<int>>& graph, int source, int target) {
    vector<int> prevNodes(graph.size());
    int result = 0;

    int minEdge = findMinEdge(graph, prevNodes, source, target);
    while (minEdge > 0) {
        int currNode = target;
        // Update the graph with new path (must reverse it)
        while (currNode != source) {
            int prev = prevNodes[currNode];
            graph[prev][currNode] -= minEdge;
            graph[currNode][prev] += minEdge;
            currNode = prev;
        }
        result += minEdge;
        minEdge = findMinEdge(graph, prevNodes, source, target);
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