# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def lcaDeepestLeaves(self, root: TreeNode) -> TreeNode:
        def dfs(root):
            if not root: return None, 0
            ln, lh=dfs(root.left)
            rn, rh=dfs(root.right)
            if lh==rh: return (root, lh+1)
            else: return (ln, lh+1) if lh>rh else (rn, rh+1)
        node, height=dfs(root)
        return node

