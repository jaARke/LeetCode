#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for (int i = nums.size() - 1; i > 0; i--) {
            if (nums[i] >= nums[i - 1]) {
                swap(nums[i], nums[i - 1]);
                return;
            }
        }
        sort(begin(nums), end(nums));
    }
};