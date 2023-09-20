#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        map<int, int> m;
        for (auto& v : nums) {
            for (int i : v) {
                m[i]++;
            }
        }
        
        vector<int> res;
        for (auto& i : m) {
            if (i.second == nums.size()) res.push_back(i.first);
        }
        return res;
    }
};