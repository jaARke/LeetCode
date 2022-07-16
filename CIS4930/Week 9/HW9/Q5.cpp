#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


int main() {
    int p, t;
    cin >> p >> t;

    vector<vector<pair<int, int>>> graph(p);
    vector<long long> distances(p, INT64_MAX);
    vector<int> trails(t);
    vector<vector<pair<int, int>>> parentTrails(p);
    queue<int> q; 
    for (int i = 0; i < t; i++) {
        int p1, p2, dis;
        cin >> p1 >> p2 >> dis;
        graph[p1].push_back(make_pair(p2, i));
        graph[p2].push_back(make_pair(p1, i));
        trails[i] = dis;
    }
    q.push(0);
    distances[0] = 0;
    while (!q.empty()) {
        int u = q.front(); 
        q.pop();
        for (auto& v : graph[u]) {
            if (distances[v.first] > distances[u] + trails[v.second]) {
                distances[v.first] = distances[u] + trails[v.second];
                q.push(v.first);
                parentTrails[v.first].clear();
                parentTrails[v.first].push_back(make_pair(v.second, u));
            }
            else if (distances[v.first] == distances[u] + trails[v.second]) {
                parentTrails[v.first].push_back(make_pair(v.second, u));
            }
        }
    }
    long long result = 0;
    vector<bool> seen(t, false);
    queue<pair<int, int>> q2;
    for (auto& v : parentTrails[p - 1]) {
        if (!seen[v.first]) {
            q2.push(v);
            seen[v.first] = true;
        }
    }
    while (!q2.empty()) {
        result += trails[q2.front().first];
        for (auto& v : parentTrails[q2.front().second]) {
            if (!seen[v.first]) {
                q2.push(v);
                seen[v.first] = true;
            }
        }
        q2.pop();
    }
    cout << result * 2 << endl;
    return 0;
}