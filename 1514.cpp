#include <bits/stdc++.h>

using namespace std;

int speed_up = []{
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // Construct the adjacency list
        vector<vector<pair<int, double>>> adjList(n);
        for (int i = 0; i < edges.size(); i++) {
            adjList[edges[i][0]].push_back(make_pair(edges[i][1], abs(log10(succProb[i]))));
            adjList[edges[i][1]].push_back(make_pair(edges[i][0], abs(log10(succProb[i]))));
        }

        // SPFA
        queue<int> q;
        vector<double> paths(n, INT32_MAX);
        vector<bool> inq(n, false);

        q.push(start_node);
        inq[start_node] = true;
        paths[start_node] = 0;
        while (!q.empty()) {
            int u = q.front();
            inq[u] = false;
            q.pop();

            for (auto& x : adjList[u]) {
                if (paths[u] + x.second < paths[x.first]) {
                    paths[x.first] = paths[u] + x.second;
                    if (!inq[x.first]) {
                        q.push(x.first);
                        inq[x.first] = true;
                    }
                }
            }
        }

        return pow(10, -paths[end_node]);
    }
};


int main() {
    Solution s;
    int n = 3;
    vector<vector<int>> edges = {{0,1},{1,2},{0,2}};
    vector<double> succProb = {0.5,0.5,0.2};
    int start = 0;
    int end = 2;

    cout << s.maxProbability(n, edges, succProb, start, end) << endl;

    return 0;
}