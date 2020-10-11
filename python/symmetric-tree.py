# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        def isSymmetric(l, r):
            if not l and not r: return True
            elif (l and not r) or (not l and r): return False
            else:
                return l.val==r.val and isSymmetric(l.left, r.right) and isSymmetric(l.right, r.left)
            
        if not root: return True
        return isSymmetric(root.left, root.right)

