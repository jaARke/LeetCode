#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        // Calculate the total sum of nums
        for (int i = 0; i < nums.size(); i++) {
            totalSum += nums[i];
        }
        // If the total sum is odd, it cannot be partitioned into two equal subsets
        if (totalSum % 2 != 0) {
            return false;
        }
        // Two subsets of equal sum must have sum half of the totalSum
        int targetSum = totalSum / 2;
        /* 
        Construct the dp array. Consider the nums one at a time and see if they can add up to each entry up to targetSum. If any subsequence of the nums
        can reach a sum of targetSum, then nums is able to be partitioned into two subsets of equal sum.
        */
        vector<vector<bool>> dp(nums.size() + 1, vector<bool>(targetSum + 1, false));
        for (int i = 0; i <= nums.size(); i++) {
            dp[i][0] = true;
        }
        for (int i = 1; i <= nums.size(); i++) {
            for (int j = 1; j <= targetSum; j++) {
                bool incl = false;
                bool excl = dp[i - 1][j];
                if (j >= nums[i - 1]) {
                    incl = dp[i - 1][j - nums[i - 1]];
                }
                dp[i][j] = incl || excl;
            }
        }
        // Check to see if, with all the nums considered, the targetSum can be reached
        return dp[nums.size()][targetSum];
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,2,3,5};
    cout << s.canPartition(nums) << endl;
    return 0;
}