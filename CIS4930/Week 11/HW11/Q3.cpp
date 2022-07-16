#include <vector>

using namespace std;

class Solution {
public:
    void checkBipartite(vector<vector<int>>& graph, vector<int>& visited, bool& flag, int node, int visNum) {
        if (visited[node] != 0) {  // This node has already been visited -> check for a cycle and return
            if (visited[node] != visNum) {
                flag = false;
            }
            return;
        }
        visited[node] = visNum;
        if (visNum == 1) {
            visNum = 2;
        }
        else {
            visNum = 1;
        }
        for (auto& x : graph[node]) {
            checkBipartite(graph, visited, flag, x, visNum);
        }
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n + 1);
        vector<int> visited(n + 1, 0);
        for (int i = 0; i < dislikes.size(); i++) {
            graph[dislikes[i][0]].push_back(dislikes[i][1]);
            graph[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        bool flag = true;
        for (int i = 1; i <= n; i++) {
            if (visited[i] == 0) {
                checkBipartite(graph, visited, flag, i, 1);
                if (!flag) {
                    return false;
                }
            }
        }
        return true;
    }
};