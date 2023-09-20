#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<vector<int>>> temp(groupSizes.size() + 1);

        for (int i = 0; i < groupSizes.size(); i++) {
            if (temp[groupSizes[i]].empty() || temp[groupSizes[i]].back().size() == groupSizes[i]) {
                temp[groupSizes[i]].push_back({i});
            }
            else {
                temp[groupSizes[i]].back().push_back(i);
            }
        }

        vector<vector<int>> res;
        for (auto& x : temp) {
            for (auto& y : x) {
                res.push_back(y);
            }
        }
        return res;
    }
};