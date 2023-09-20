#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<long long> dp(target + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= target; i++) {
            for (int n : nums) {
                if (n <= i && dp[i] < INT_MAX) {
                    dp[i] += dp[i - n];
                }
            }
        }
        return dp[target];
    }
};

int main() {
    Solution s;
    vector<int> nums = {9};
    int target = 3;
    cout << s.combinationSum4(nums, target) << endl;
    return 0;
}