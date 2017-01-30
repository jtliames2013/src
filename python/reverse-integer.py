class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        res = 0
        n = abs(x)
        while n>0:
            res = res*10+n%10
            n /= 10
        if res > 1<<32-1:
            res = 0
        return res if x>=0 else -res
