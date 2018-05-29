# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pruneTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        if root is None: return None
        root.left=self.pruneTree(root.left)
        root.right=self.pruneTree(root.right)
        if root.left is not None or root.right is not None or root.val==1: return root
        return None
