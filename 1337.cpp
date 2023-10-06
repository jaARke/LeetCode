#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (int i = 0; i < mat.size(); i++) {
            int sum = 0;
            for (int j = 0; j < mat[i].size(); j++) {
                sum += mat[i][j];
            }
            pq.push(make_pair(sum, i));
        }

        vector<int> res;
        for (int i = 0; i < k; i ++) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};