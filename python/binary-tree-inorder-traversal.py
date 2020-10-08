# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        res, stk, n=[], [], root
        while n:
            stk.append(n)
            n=n.left
        while stk:
            t=stk.pop()
            res.append(t.val)
            n=t.right
            while n:
                stk.append(n)
                n=n.left

        return res

