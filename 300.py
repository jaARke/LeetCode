from ast import List
from bisect import bisect_left

class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        lis = []
        for x in nums:
            idx = bisect_left(lis, x, 0, len(lis))
            if idx == len(lis):
                lis.append(x)
            else:
                lis[idx] = x
        return len(lis)