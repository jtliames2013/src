# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        def dfs(root):
            nonlocal res
            if not root: return 0
            l, r=dfs(root.left), dfs(root.right)
            res=max(res, max(l, 0)+root.val+max(r, 0))
            return max(l, r, 0)+root.val
        res=float('-inf')
        dfs(root)
        return res

