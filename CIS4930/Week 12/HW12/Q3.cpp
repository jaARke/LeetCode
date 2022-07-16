#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool runDFS(int node, int color, int& count1, int& count2, vector<int>& vis, vector<vector<int>>& adjList) {
    if (color == 1) {
        count1++;
    }
    else {
        count2++;
    }
    vis[node] = color;
    color = 3 - color;

    for (auto& x : adjList[node]) {
        if (vis[x] == 0) {
            if (!runDFS(x, color, count1, count2, vis, adjList)) {
                return false;
            }
        }
        else {
            if (vis[x] == vis[node]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;
        
        // Compute powers of two modulo for combination calculations (couldn't use pow() without overflow)
        vector<long long> powMods(n + 1);
        powMods[0] = 1;
        for (int i = 1; i <= n; i++) {
            powMods[i] = (powMods[i - 1] * 2) % 998244353;
        }

        vector<vector<int>> adjList(n + 1);
        for (int i = 0; i < m; i++) {
            int vi, ui;
            cin >> vi >> ui;
            adjList[vi].push_back(ui);
            adjList[ui].push_back(vi);
        }

        vector<int> vis(n + 1, 0);
        long long result = 1;
        bool flag = false;
        for (int i = 1; i <= n; i ++) {
            int count1 = 0, count2 = 0;
            if (vis[i] == 0) {
                if (!runDFS(i, 1, count1, count2, vis, adjList)) {
                    flag = true;
                    break;
                }
                result = (result * ((powMods[count1] + powMods[count2]) % 998244353) % 998244353);
            }
        }
        if (flag) {
            cout << "0\n";
        }
        else {
            cout << result << '\n';
        }
    }
    return 0;
}