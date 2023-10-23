#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    void runBFS(int i, vector<bool>& seen, vector<vector<int>>& connected) {
        queue<int> q;
        q.push(i);

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (int j = 0; j < connected[v].size(); j++) {
                if (connected[v][j] && !seen[j]) {
                    q.push(j);
                    seen[j] = true;
                }
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> seen(isConnected.size(), false);

        int res = 0;
        for (int i = 0; i < isConnected.size(); i++) {
            if (!seen[i]) {
                res++;
                seen[i] = true;
                runBFS(i, seen, isConnected);
            }
        }
        return res;
    }
};