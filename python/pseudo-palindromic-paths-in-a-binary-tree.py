# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, root, count=0):
        if not root: return 0
        res=0
        count ^= 1<<root.val
        if root.left is None and root.right is None:
            if (count & (count-1)) == 0: res+=1
        res+=self.dfs(root.left, count)+self.dfs(root.right, count)
        return res
    
    def pseudoPalindromicPaths (self, root: TreeNode) -> int:
        return self.dfs(root)
