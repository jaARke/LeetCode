#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums) {
        int add = 1;
        long long res = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) add++;
            else add = 1;
            res += add;
        }
        return res;
    }
};