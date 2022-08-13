class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        def recHelper(p, q, root):
            if root in [p, q, None]:
                return root
        
            left = recHelper(p, q, root.left)
            right = recHelper(p, q, root.right)

            if left and right:
                return root
            if left:
                return left
            if right:
                return right

        return recHelper(p, q, root)

        
        