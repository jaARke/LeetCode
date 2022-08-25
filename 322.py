from ast import List
from cmath import inf

class Solution:
    def coinChange(self, coins, amount) -> int:
        dp = [[inf] * (amount + 1) for _ in range(len(coins) + 1)]
        for i in range(1, len(coins) + 1):
            for j in range(0, amount + 1):
                if j == 0:
                    dp[i][j] = 0
                    continue
                if j - coins[i - 1] >= 0 and dp[i][j - coins[i - 1]] != inf:
                    dp[i][j] = min(1 + dp[i][j - coins[i - 1]], dp[i - 1][j])
                else:
                    dp[i][j] = dp[i - 1][j]
        if dp[len(coins)][amount] != inf:
            return dp[len(coins)][amount]
        return -1

s = Solution
print(s.coinChange(s, coins=[2147483647], amount=2))