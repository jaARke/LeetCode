#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if (nums.size() < 2) {
            return true;
        }
        bool inc = true, dec = true;

        for (int i = 1; i < nums.size() && (inc || dec); i++) {
            inc = inc && nums[i] >= nums[i - 1];
            dec = dec && nums[i] <= nums[i - 1];
        }
        return inc || dec;
    }
};