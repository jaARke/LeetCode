#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq(begin(intervals), end(intervals));

        vector<vector<int>> res;
        while(!pq.empty()) {
            int start = pq.top()[0];
            int end = pq.top()[1];
            pq.pop();

            while (!pq.empty() && pq.top()[0] <= end) {
                end = max(end, pq.top()[1]);
                pq.pop();
            }
            res.push_back({start, end});
        }
        return res;
    }
};