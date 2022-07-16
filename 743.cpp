#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> G(n + 1);
        for (int i = 0; i < times.size(); i++) {
            G[times[i][0]].push_back(make_pair(times[i][1], times[i][2]));
        }
        vector<int> dis(n + 1, INT32_MAX);
        vector<bool> vis(n + 1, false);
        queue<int> q;
        q.push(k);
        dis[k] = 0;
        vis[k] = true;

        while (!q.empty()) {
            int ui = q.front(); // Stores the index of the node being considered
            vector<pair<int, int>> vi = G[ui];  // Stores a list of the adjacent nodes and the weights of the edges to each
            vis[ui] = false;
            q.pop();

            for (int i = 0; i < vi.size(); i++) {
                if (dis[vi[i].first] > dis[ui] + vi[i].second) {
                    dis[vi[i].first] = dis[ui] + vi[i].second;
                    if (!vis[vi[i].first]) {
                        vis[vi[i].first] = true;
                        q.push(vi[i].first);
                    }
                }
            }
        }
        int ans = *max_element(dis.begin() + 1, dis.end());
        return (ans == INT32_MAX ? -1 : ans);
    }
};

int main() {
    Solution s;
    vector<vector<int>> times = {{1,2,1},{2,3,2},{1,3,4}};
    int n = 3;
    int k = 1;
    s.networkDelayTime(times, n, k);
    return 0;
}