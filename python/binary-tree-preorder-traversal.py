# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        if not root: return []
        res, stk=[], [root]
        while stk:
            t=stk.pop()
            res.append(t.val)
            if t.right: stk.append(t.right)
            if t.left: stk.append(t.left)
        return res

