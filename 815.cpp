#include <bits/stdc++.h>

using namespace std;

/**
 * DOES NOT WORK -> TLE
*/

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;

        unordered_map<int, vector<int>> adjList;    // Holds buses that visit a given station
        for (int i = 0; i < routes.size(); i++) {
            for (int j : routes[i]) {
                adjList[j].push_back(i);
            }
        }

        queue<pair<int, int>> q;    // Holds buses
        unordered_map<int, bool> seenStation, seenBus;
        for (int i : adjList[source]) {
            q.push({i, 1});
            seenBus[i] = true;
        }
        seenStation[source] = true;

        while (!q.empty()) {
            auto u = q.front();
            q.pop();

            for (int i : routes[u.first]) {
                if (i == target) return u.second;
                if (!seenStation[i]) {
                    seenStation[i] = true;
                    for (int j : adjList[i]) {
                        if (!seenBus[j]) q.push({j, u.second + 1});
                    }
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<vector<int>> routes = {{1,2,7},{3,6,7}};
    int source = 1, target = 6;
    cout << s.numBusesToDestination(routes, source, target) << endl;
    return 0;
}