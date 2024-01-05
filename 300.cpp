#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> LIS;
        for (auto i : nums) {
            auto iter = lower_bound(begin(LIS), end(LIS), i);
            if (iter == end(LIS)) LIS.push_back(i);
            else *iter = i;
        }
        return LIS.size();
    }
};