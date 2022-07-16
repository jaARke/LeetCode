#include <vector>

using namespace std;

class Solution {
public:
    bool checkBipartite(vector<vector<int>>& graph, vector<int>& visited, int node, int visNum) {
        if (visited[node] != 0) {  // This node has already been visited -> check for a cycle and return
            if (visited[node] != visNum) {
                return false;
            }
            return true;
        }
        visited[node] = visNum;
        if (visNum == 1) {
            visNum = 2;
        }
        else {
            visNum = 1;
        }
        for (auto& x : graph[node]) {
            if (!checkBipartite(graph, visited, x, visNum)) {
                return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n + 1);
        vector<int> visited(n + 1, 0);
        for (int i = 0; i < dislikes.size(); i++) {
            graph[dislikes[i][0]].push_back(dislikes[i][1]);
            graph[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        for (int i = 1; i <= n; i++) {
            if (visited[i] == 0) {
                if (!checkBipartite(graph, visited, i, 1)) {
                    return false;
                }
            }
        }
        return true;
    }
};