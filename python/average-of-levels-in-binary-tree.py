# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfLevels(self, root: TreeNode) -> List[float]:
        res, q=[], [root]
        while q:
            l, sum=len(q), 0
            for i in range(l):
                n=q.pop(0)
                sum+=n.val
                if n.left: q.append(n.left)
                if n.right: q.append(n.right)
            res.append(sum/l)
        return res

