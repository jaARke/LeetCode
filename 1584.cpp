#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> dists(points.size(), vector<int>(points.size()));
        for(int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                dists[i][j] = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                dists[j][i] = dists[i][j];
            }
        }

        unordered_set<int> unseen;
        vector<int> mst(points.size(), INT32_MAX);

        for (int i = 1; i < points.size(); i++) {
            unseen.insert(i);
            mst[i] = dists[0][i];
        }
        mst[0] = 0;

        while (!unseen.empty()) {
            int currMin = -1;
            for (int i : unseen) {
                if (currMin == -1 || mst[currMin] > mst[i]) {
                    currMin = i;
                }
            }

            unseen.extract(currMin);

            for (int i : unseen) {
                mst[i] = min(mst[i], dists[currMin][i]);
            } 
        }

        int sum = 0;
        for (auto& x : mst) {
            sum += x;
        }
        return sum;
    }
};

int main() {
    Solution s;
    vector<vector<int>> points = {{0,0},{2,2},{3,10},{5,2},{7,0}};
    cout << s.minCostConnectPoints(points) << endl;
    return 0;
}