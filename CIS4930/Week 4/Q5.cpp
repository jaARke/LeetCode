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

        // Load all the coordinates into an (x, y) vector
        vector<pair<int, int>> coords;
        for (int j = 0; j < p; j++) {
            int x;
            int y;
            cin >> x >> y;
            coords.push_back(make_pair(x, y));
        }

        // Run Prim's
        unordered_set<int> visited;
        vector<double> distances(coords.size(), DBL_MAX);
        int currIdx = 0;  // Stores the post you are finding a path from
        int nextIdx = 0;    // Stores the next post based on the minimum distance from the current post
        visited.insert(currIdx);
        distances[currIdx] = 0;
        // Go through each post after the first and find the minimum distance required to get from it to another
        for (int j = 1; j < coords.size(); j++) {
            // Go through every other post and calculate distance from the one being considered
            double minimumDist = DBL_MAX;   // Stores the minimum distance found on each iteration
            for (int k = 0; k < coords.size(); k++) {
                // Calculate the distance to every post not yet visited
                if (visited.find(k) == visited.end()) {
                    // Overwrite if the distance is smaller than that between a post already considered
                    distances[k] = min(calcDistance(coords[currIdx], coords[k]), distances[k]);
                    if (distances[k] < minimumDist) {
                        minimumDist = distances[k];
                        nextIdx = k;
                    }
                }
            }
            currIdx = nextIdx;
            visited.insert(currIdx);
        }
        sort(distances.begin(), distances.end());
        cout << fixed << setprecision(2) << distances[distances.size() - s] << endl;
    }
    return 0;
}