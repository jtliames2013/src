# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isCousins(self, root: 'TreeNode', x: 'int', y: 'int') -> 'bool':
        def dfs(root, d, parent, depth):
            if not root: return
            d[root.val]=[parent, depth]
            dfs(root.left, d, root.val, depth+1)
            dfs(root.right, d, root.val, depth+1)
        d=dict()
        dfs(root, d, 0, 0)
        return d[x][1]==d[y][1] and d[x][0]!=d[y][0]

