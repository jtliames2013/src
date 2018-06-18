class Solution:
    def largestOverlap(self, A, B):
        """
        :type A: List[List[int]]
        :type B: List[List[int]]
        :rtype: int
        """
        n=len(A)
        stA=[[i, j] for i in range(n) for j in range(n) if A[i][j]==1]
        stB=[[i, j] for i in range(n) for j in range(n) if B[i][j]==1]
        c=collections.Counter((a[0]-b[0], a[1]-b[1]) for a in stA for b in stB)
        return max(c.values() or [0])
