#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    void recHelper(int v, vector<vector<int>>& graph, vector<bool>& res, vector<bool>& seen) {
        seen[v] = true;
        if (graph[v].empty()) {
            res[v] = true;
            return;
        }
        bool flag = true;
        for (auto& x : graph[v]) {
            if (!seen[x]) {
                recHelper(x, graph, res, seen);
            }
            flag = res[x];
            if (!flag) break;
        }
        res[v] = flag;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<bool> res(graph.size(), false);
        vector<bool> seen(graph.size(), false);
        for (int i = 0; i < graph.size(); i++) {
            recHelper(i, graph, res, seen);
        }

        vector<int> resParsed;
        for (int i = 0; i < res.size(); i++) {
            if (res[i]) resParsed.push_back(i);
        }
        return resParsed;
    }
};

