# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, root, mx):
        if not root: return 0
        res=1 if root.val>=mx else 0
        res+=self.dfs(root.left, max(root.val, mx))+self.dfs(root.right, max(root.val, mx))
        return res
    
    def goodNodes(self, root: TreeNode) -> int:
        return self.dfs(root, float('-inf'))
    
