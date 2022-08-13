from cmath import inf
from typing import Optional

# Traverse the tree recursively. Each time you take a left branch, update your upper bound to be the current root value (no node in the left branch can be greater or equal to this). Each time you take a right branch, update your lower bound
# to be the current root value by the same logic. 

class TreeNode:
     def __init__(self, val=0, left=None, right=None):
         self.val = val
         self.left = left
         self.right = right

class Solution:
    def recHelper(self, root: Optional[TreeNode], upper, lower) -> bool:
        if root is None:
            return True
        if root.val <= lower or root.val >= upper:
            return False
        return self.recHelper(root.left, root.val, lower) and self.recHelper(root.right, upper, root.val)
        
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        return self.recHelper(root, inf, -inf)
