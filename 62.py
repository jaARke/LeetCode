# Top-down dp -> start from (0,0) position and recursively move down and right. If you reach the target, you've found a path, so return 1. If you go out of bounds, return 0. Each position's value is the number of unique paths from that position to the exit.
# Recursive relation is dp[i][j] = dp[i + 1][j] + dp[i][j + 1] -> the number of paths at one location is the sum of the paths at the location to the right and the location below it.

class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp = [[-1] * (n) for _ in range(m)]

        def recHelper(i, j):
            if i >= m or j >= n:
                return 0
            if i == m - 1 and j == n - 1:
                return 1
            if dp[i][j] != -1:
                return dp[i][j]
            
            dp[i][j] = recHelper(i + 1, j) + recHelper(i, j + 1)

            return dp[i][j]

        return recHelper(0, 0)

s = Solution()
print(s.uniquePaths(3, 7))