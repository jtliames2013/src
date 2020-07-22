# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        res=[]
        if not root: return res
        q=[root]
        while q:
            size=len(q)
            v=[]
            for i in range(size):
                f=q.pop(0)
                v.append(f.val)
                if f.left: q.append(f.left)
                if f.right: q.append(f.right)
            res.append(v)
            
        return res
