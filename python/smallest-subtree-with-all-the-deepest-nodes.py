# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def subtreeWithAllDeepest(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        def dfs(root):
            if root==None: return [0, None]
            l=dfs(root.left)
            r=dfs(root.right)
            if l[0]==r[0]: return [l[0]+1, root]
            elif l[0]>r[0]: return [l[0]+1, l[1]] 
            else: return [r[0]+1, r[1]]
        
        return dfs(root)[1]
