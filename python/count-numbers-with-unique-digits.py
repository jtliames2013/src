class Solution:
    def countNumbersWithUniqueDigits(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n==0: return 1
        n=min(n, 9)
        
        res, prod=10, 9
        for i in range(1, n):
            prod*=(10-i)
            res+=prod
            
        return res
        
