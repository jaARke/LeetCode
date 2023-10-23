#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bool hasOne = false;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) hasOne = true;
            if (nums[i] <= 0 || nums[i] > nums.size()) nums[i] = 1;
        }
        if (!hasOne) return 1;

        for (int i = 0; i < nums.size(); i++) {
            int j = abs(nums[i]) % nums.size();

            nums[j] = -abs(nums[j]);
        }
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > 0) return i;
        }
        return (nums[0] > 0 ? nums.size() : nums.size() + 1);
    }
};