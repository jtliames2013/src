# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class BSTIterator:

    def __init__(self, root: TreeNode):
        self.stk=[]
        n=root
        while n:
            self.stk.append(n)
            n=n.left

    def next(self) -> int:
        """
        @return the next smallest number
        """
        if not self.hasNext(): return -1
        res=self.stk.pop()
        n=res.right
        while n:
            self.stk.append(n)
            n=n.left
        
        return res.val

    def hasNext(self) -> bool:
        """
        @return whether we have a next smallest number
        """
        return self.stk


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()
