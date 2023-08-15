#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        vector<int> counts(nums.size(), 1);
        int currMax = 1;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        counts[i] = counts[j];
                    }
                    else if (dp[i] == dp[j] + 1) {
                        counts[i] += counts[j];
                    }
                }
                currMax = max(currMax, dp[i]);
            }
        }

        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (dp[i] == currMax) {
                res += counts[i];
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,3,5,4,7};

    cout << s.findNumberOfLIS(nums) << endl;
    return 0;
}