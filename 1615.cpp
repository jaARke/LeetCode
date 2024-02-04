#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<bool>> adjList(n, vector<bool>(n, false));
        vector<int> rank(n, 0);
        int res = 0;
        for (auto& x : roads) {
            adjList[x[0]][x[1]] = true;
            adjList[x[1]][x[0]] = true;
            rank[x[0]]++;
            rank[x[1]]++;
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                res = max(res, (rank[i] + rank[j]) - adjList[i][j]);
            }
        }
        return res;
    }
};

// Test

int main() {
    Solution s;
    int n = 5;
    vector<vector<int>> roads = {{0,1},{0,3},{1,2},{1,3},{2,3},{2,4}};
    cout << s.maximalNetworkRank(n, roads) << endl;
    return 0;
}