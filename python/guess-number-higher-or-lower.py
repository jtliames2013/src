# The guess API is already defined for you.
# @param num, your guess
# @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
# def guess(num):

class Solution(object):
    def guessNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        l, r=1, n
        while l<=r:
            mid=int(l+(r-l)/2)
            res=guess(mid)
            if res==0: return mid
            elif res==-1: r=mid-1
            else: l=mid+1
