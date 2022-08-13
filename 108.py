from ast import List
from queue import Empty
from typing import Optional


class TreeNode:
     def __init__(self, val=0, left=None, right=None):
         self.val = val
         self.left = left
         self.right = right

class Solution:
    def sortedArrayToBST(self, nums):
        if not nums:
            return None
        head = TreeNode(val=nums[int(len(nums) / 2)])
        head.left = self.sortedArrayToBST(nums[:int(len(nums) / 2)])
        head.right = self.sortedArrayToBST(nums[int((len(nums) / 2)) + 1:])
        return head

s = Solution
s.sortedArrayToBST(s, [-10,-3,0,5,9])
print("Done!")