#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, INT32_MAX));
        dp[0][0] = 0;

        for (int i = 1; i <= coins.size(); i++) {
            dp[i][0] = 0;
            for (int j = 1; j <= amount; j++) {
                int noTake = dp[i - 1][j];
                int take = INT32_MAX;
                if (j >= coins[i - 1] && dp[i][j - coins[i - 1]] != INT32_MAX) take = dp[i][j - coins[i - 1]] + 1;
                dp[i][j] = min(noTake, take);
            }
        }
        return (dp[coins.size()][amount] == INT32_MAX ? -1 : dp[coins.size()][amount]);
    }
};

int main() {
    Solution s;
    vector<int> coins = {2};
    int amount = 3;
    cout << s.coinChange(coins, amount) << endl;
    return 0;
}