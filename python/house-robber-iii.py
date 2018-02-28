# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def rob(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        def dfs(root):
            if root is None: return (0,0)
            l=dfs(root.left)
            r=dfs(root.right)
            return (root.val+l[1]+r[1], max(l[0], l[1])+max(r[0], r[1]))
        
        res=dfs(root)
        return max(res[0], res[1])
        

