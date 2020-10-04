# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isEvenOddTree(self, root: TreeNode) -> bool:
        q=[root]
        level=0
        while q:
            size=len(q)
            prev=-1
            for i in range(size):
                f=q.pop(0)
                if (level%2==0 and f.val%2==0) or \
                   (level%2==1 and f.val%2==1): return False
                if prev!=-1:
                    if (level%2==0 and prev>=f.val) or \
                       (level%2==1 and prev<=f.val): return False
                prev=f.val
                if f.left: q.append(f.left)
                if f.right: q.append(f.right)
            level+=1
            
        return True
        
