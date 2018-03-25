1.
class Solution:
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """        
        l, r=0, x
        while l<=r:
            mid=int(l+(r-l)/2)
            s=mid*mid
            if s==x: return mid
            elif s<x: l=mid+1
            else: r=mid-1
        
        return r

2.
class Solution:
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """        
        l, r=0, x
        while l<r:
            mid=int(l+(r-l)/2+1)
            s=mid*mid
            if s==x: return mid
            elif s<x: l=mid
            else: r=mid-1
        
        return r
