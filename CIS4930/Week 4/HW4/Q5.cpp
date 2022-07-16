#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
#include <unordered_set>
#include <bits/stdc++.h>

using namespace std;

double calcDistance(pair<int, int> p1, pair<int, int> p2) {
    return sqrt(pow((double)p2.first - (double)p1.first, 2) + pow((double)p2.second - (double)p1.second, 2));
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int s;
        int p;
        cin >> s >> p; 

        vector<pair<int, int>> coords;
        for (int j = 0; j < p; j++) {
            int x;
            int y;
            cin >> x >> y;
            coords.push_back(make_pair(x, y));
        }
        // Run Prim's
        unordered_set<int> visited;
        vector<double> distances(coords.size(), -1);
        int index = 0;
        visited.insert(index);
        distances[index] = 0;
        for (int j = 1; j < coords.size(); j++) {
            for (int k = 0; k < coords.size(); k++) {
                if (visited.find(k) == visited.end() && (calcDistance(coords[index], coords[k]) < distances[k] || distances[k] == -1)) {
                    distances[k] = calcDistance(coords[index], coords[k]);
                }
            }
            double minimumDist = -1;
            for (int k = 0; k < coords.size(); k++) {
                if (visited.find(k) == visited.end() && (distances[k] < minimumDist || minimumDist == -1)) {
                    minimumDist = distances[k];
                    index = k;
                }
            }
            visited.insert(index);
        }
        sort(distances.begin(), distances.end());
        cout << fixed << setprecision(2) << distances[distances.size() - s] << endl;
    }
    return 0;
}