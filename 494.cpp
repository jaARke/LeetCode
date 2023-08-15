#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int recHelper(vector<int>& nums, int curr, int target, int idx, vector<vector<int>>& memo) {
        if (idx == nums.size()) {
            if (curr == target) {
                return 1;
            }
            return 0;
        }

        if (memo[curr + 1000][idx] != -1) {
            return memo[curr + 1000][idx];
        }
        
        return memo[curr + 1000][idx] = recHelper(nums, curr + nums[idx], target, idx + 1, memo) + recHelper(nums, curr - nums[idx], target, idx + 1, memo);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<vector<int>> memo(2001, vector<int>(nums.size(), -1));
        return recHelper(nums, 0, target, 0, memo);
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,1,1,1,1};
    int target = 3;
    cout << s.findTargetSumWays(nums, target) << endl;
    return 0;
}