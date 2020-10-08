# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        res, stk, n, lastVisited=[], [], root, None
        while stk or n:
            if n:
                stk.append(n)
                n=n.left
            else:
                peek=stk[-1]
                if peek.right and peek.right!=lastVisited:
                    n=peek.right
                else:
                    res.append(peek.val)
                    lastVisited=peek
                    stk.pop()
        return res

