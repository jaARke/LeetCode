from ast import List
from cmath import inf

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        currMin = prices[0]
        res = 0
        for i in range(1, len(prices)):
            res = max(res, prices[i] - currMin)
            currMin = min(currMin, prices[i])
        return res
