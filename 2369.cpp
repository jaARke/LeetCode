#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool validPartition(vector<int>& nums) {
        vector<bool> dp(nums.size() + 1, false);
        dp[0] = true;

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1] && dp[i - 1]) {
                dp[i + 1] = true;
            }
            else if (i > 1 && nums[i] == nums[i - 1] && nums[i - 1] == nums[i - 2] && dp[i - 2]) {
                dp[i + 1] = true;
            }
            else if (i > 1 && (nums[i] - nums[i - 1]) == (nums[i - 1] - nums[i - 2]) && (nums[i] - nums[i - 1]) == 1 && dp[i - 2]) {
                dp[i + 1] = true;
            }
        }
        return dp[nums.size()];
    }
};

int main() {
    Solution s;
    vector<int> nums = {803201,803201,803201,803201,803202,803203};
    cout << s.validPartition(nums) << endl;
    return 0;
}