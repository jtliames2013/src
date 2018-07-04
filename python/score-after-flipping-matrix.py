class Solution:
    def matrixScore(self, A):
        """
        :type A: List[List[int]]
        :rtype: int
        """
        m, n=len(A), len(A[0])
        res=m*(1<<(n-1))
        for j in range(1,n):
            cnt=sum(A[i][0]==A[i][j] for i in range(m))
            res+=max(cnt, m-cnt)*(1<<(n-1-j))
        return res
