# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sumRootToLeaf(self, root: TreeNode) -> int:
        def getSum(self, node, num):
            if node==None: return
            if node.left==None and node.right==None:
                self.res+=num*2+node.val
            getSum(self, node.left, num*2+node.val)
            getSum(self, node.right, num*2+node.val)
        self.res=0
        getSum(self, root, 0)
        return self.res
