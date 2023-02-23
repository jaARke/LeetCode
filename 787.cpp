#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<vector<int>>> adjList(n);
        vector<vector<vector<int>>> paths(n);
        queue<int> q;
        int ans = INT32_MAX;
        for (auto& x : flights) {
            adjList[x[0]].push_back({x[1], x[2]});
        }
        paths[src].push_back({0, -1});
        q.push(src);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            while (!paths[u].empty()) {
                if (u == dst) {
                    if (paths[u].back()[1] <= k) {
                        ans = min(ans, paths[u].back()[0]);
                    }
                    paths[u].pop_back();
                    continue;
                }
                if (paths[u].back()[1] >= k) {
                    paths[u].pop_back();
                    continue;
                }
                for (auto& y : adjList[u]) {
                    if (paths[y[0]].empty()) { 
                        q.push(y[0]);
                    }
                    paths[y[0]].push_back({paths[u].back()[0] + y[1], paths[u].back()[1] + 1});
                }
                paths[u].pop_back();
            }
        }
        return (ans == INT32_MAX ? -1 : ans);
    }
};

int main() {
    Solution s;
    vector<vector<int>> flights = {{3,4,4},{2,5,6},{4,7,10},{9,6,5},{7,4,4},{6,2,10},{6,8,6},{7,9,4},{1,5,4},{1,0,4},{9,7,3},{7,0,5},{6,5,8},{1,7,6},{4,0,9},{5,9,1},{8,7,3},{1,2,6},{4,1,5},{5,2,4},{1,9,1},{7,8,10},{0,4,2},{7,2,8}};
    cout << s.findCheapestPrice(10, flights, 6, 0, 7) << endl;
    return 0;
}