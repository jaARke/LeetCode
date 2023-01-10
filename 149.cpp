#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int res = 1;
        for (int i = 0; i + res < points.size(); i++) {
            unordered_map<double, int> freq;    // Tracks slope frequencies
            for (int j = i + 1; j < points.size(); j++) {
                // Calculate slope between outer loop point and inner loop point
                double currSlope;
                if (points[i][0] == points[j][0]) {
                    currSlope = INT32_MAX;
                }
                else {
                    currSlope = ((double)points[j][1] - (double)points[i][1]) / ((double)points[j][0] - (double)points[i][0]);
                }
                // Check if the slope frequency indicates a new answer
                res = max(res, ++freq[currSlope] + 1);
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<vector<int>> points = {{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
    cout << s.maxPoints(points) << endl;
    return 0;
}