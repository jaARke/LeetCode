from ast import List

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums = sorted(nums)
        for i in range(len(nums)):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            targ = 0 - nums[i]
            j = i + 1
            k = len(nums) - 1
            while j < k:
                if nums[j] + nums[k] > targ:
                    k -= 1
                elif nums[j] + nums[k] < targ:
                    j += 1
                else:
                    res.append([nums[i], nums[j], nums[k]])
                    while j < k and nums[j] == nums[j + 1]:
                        j += 1
                    while j < k and nums[k] == nums[k - 1]:
                        k -= 1
                    j += 1
                    k -= 1
        return res