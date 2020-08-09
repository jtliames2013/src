# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> int:
        def dfs(root, sum):
            if not root: return 0
            res=1 if sum==root.val else 0
            return res+dfs(root.left, sum-root.val)+dfs(root.right, sum-root.val)
    
        if not root: return 0
        return dfs(root, sum)+self.pathSum(root.left, sum)+self.pathSum(root.right, sum)
        
