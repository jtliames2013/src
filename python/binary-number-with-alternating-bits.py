class Solution:
    def hasAlternatingBits(self, n):
        """
        :type n: int
        :rtype: bool
        """
        d=n&0x1
        while n>0:
            if d!=(n&0x1): return False
            d=1-d            
            n>>=1
        return True

