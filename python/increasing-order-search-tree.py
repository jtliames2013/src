# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def increasingBST(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        def dfs(root):
            if not root: return [None, None]
            head, tail=root, root
            if root.left:
                res=dfs(root.left)
                head=res[0]
                res[1].right=root
                root.left=None
            if root.right:
                res=dfs(root.right)
                tail=res[1]
                root.right=res[0]
            return [head, tail]
            
        return dfs(root)[0]
