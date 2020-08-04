1. recursive
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        def dfs(root, lower, upper):
            if not root: return True
            if root.val<=lower or root.val>=upper: return False
            return dfs(root.left, lower, root.val) and dfs(root.right, root.val, upper)
        
        return dfs(root, float('-inf'), float('inf'))

2. iterative
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        prev=float('-inf')
        stk=[]
        if not root: return True
        n=root
        while n:
            stk.append(n)
            n=n.left

        while stk:
            t=stk.pop()
            if t.val<=prev: return False
            prev=t.val

            n=t.right
            while n:
                stk.append(n)
                n=n.left
        return True
