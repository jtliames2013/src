class Solution:
    def lastRemaining(self, n):
        """
        :type n: int
        :rtype: int
        """        
        head, step, left=1, 1, True
        while n>1:            
            if left or n%2==1: head+=step
            step*=2
            n=int(n/2)
            left=not left
            
        return head
