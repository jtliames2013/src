# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        res=[]
        if not root: return res
        q=[root]
        while q:
            size=len(q)
            res.append(q[0].val)
            
            for i in range(size):
                f=q.pop(0)
                if f.right: q.append(f.right)
                if f.left: q.append(f.left)
        
        return res

