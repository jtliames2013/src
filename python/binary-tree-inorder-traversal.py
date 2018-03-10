tion for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        res, stk, n=[], [], root
        while True:            
            while n!=None:
                stk.append(n)
                n=n.left
            if len(stk)==0: return res
            
            t=stk.pop()
            res.append(t.val)
            n=t.right
                
        return res
