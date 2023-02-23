#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        priority_queue<pair<int, int>> pq;
        int res = 0;
        for (auto& x : points) {
            pq.push(make_pair(x[1], x[0]));
        }
        while (!pq.empty()) {
            int curr = pq.top().second;
            pq.pop();
            while (!pq.empty() && pq.top().first >= curr) {
                curr = max(pq.top().second, curr);
                pq.pop();
            }
            res++;
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<vector<int>> points = {{10,16},{2,8},{1,6},{7,12}};
    cout << s.findMinArrowShots(points) << endl;
    return 0;
}