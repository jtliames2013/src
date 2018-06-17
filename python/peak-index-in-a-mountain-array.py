class Solution:
    def peakIndexInMountainArray(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        l, r=0, len(A)-1
        while (l<r):
            mid=int(l+(r-l)/2)
            if A[mid]>A[mid-1] and A[mid]>A[mid+1]: return mid
            elif A[mid]>A[mid-1]: l=mid+1
            else: r=mid-1
        return l
