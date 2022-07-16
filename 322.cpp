#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, INT32_MAX));
        for (int i = 1; i <= coins.size(); i++) {
            dp[i][0] = 0;
            for (int j = 1; j <= amount; j++) {
                int incl = INT32_MAX;
                int excl = dp[i - 1][j];
                if (j >= coins[i - 1] && dp[i][j - coins[i - 1]] != INT32_MAX) {
                    incl = dp[i][j - coins[i - 1]] + 1;
                }
                dp[i][j] = min(incl, excl);
            }
        }
        if (dp[coins.size()][amount] == INT32_MAX) {
            return - 1;
        }
        else {
            return dp[coins.size()][amount];
        }
    }
};

int main() {
    Solution s;
    vector<int> coins = {1,2,5};
    int amount = 11;
    cout << s.coinChange(coins, amount) << endl;
    return 0;
}