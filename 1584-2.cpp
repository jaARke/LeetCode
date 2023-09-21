#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> dists(points.size(), vector<int>(points.size()));
        for (int i = 0; i < points.size(); i++) {
            dists[i][i] = 0;
            for (int j = i + 1; j < points.size(); j++) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                dists[i][j] = dist;
                dists[j][i] = dist;
            }
        }

        vector<int> mst(points.size(), INT32_MAX);
        unordered_set<int> unseen;
        for (int i = 1; i < points.size(); i++) {
            unseen.insert(i);
            mst[i] = dists[0][i];
        }
        mst[0] = 0;

        int res = 0;
        while (!unseen.empty()) {
            int currMin = -1;
            for (int i : unseen) {
                if (currMin == -1 || mst[i] < mst[currMin]) {
                    currMin = i;
                }
            }

            res += mst[currMin];
            unseen.erase(currMin);

            for (int i : unseen) {
                mst[i] = min(mst[i], dists[currMin][i]);
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<vector<int>> points = {{0,0},{2,2},{3,10},{5,2},{7,0}};
    cout << s.minCostConnectPoints(points) << endl;
    return 0;
}