class Solution:
    def isMonotonic(self, A):
        """
        :type A: List[int]
        :rtype: bool
        """
        inc, dec=False, False
        for i in range(1, len(A)):
            if A[i]>A[i-1]: inc=True
            if A[i]<A[i-1]: dec=True
            if inc and dec: return False
        return True
