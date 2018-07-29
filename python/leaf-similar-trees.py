# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def leafSimilar(self, root1, root2):
        """
        :type root1: TreeNode
        :type root2: TreeNode
        :rtype: bool
        """
        def dfs(node):
            if not node: return
            if node.left is None and node.right is None: yield node.val
            for i in dfs(node.left): yield i
            for i in dfs(node.right): yield i
        return all(a==b for a, b in zip(dfs(root1), dfs(root2)))
