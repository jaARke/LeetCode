#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> freqs;
        for (int i : nums) freqs[i]++;

        int res = 0;
        for (auto& iter : freqs) {
            if (iter.second == 1) return -1;
            res += ceil(iter.second / 3.0);
        }
        return res;
    }
};