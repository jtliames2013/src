class Solution:
    def isPerfectSquare(self, num):
        """
        :type num: int
        :rtype: bool
        """
        l, r=1, num
        while l<=r:
            mid=int(l+(r-l)/2)
            if mid*mid==num: return True
            elif mid*mid<num: l=mid+1
            else: r=mid-1
        
        return False
