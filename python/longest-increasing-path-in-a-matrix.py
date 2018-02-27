class Solution:
    def longestIncreasingPath(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        """
        def dfs(i, j):
            if not dp[i][j]:
                val=matrix[i][j]
                dp[i][j]=1+max(
                    dfs(i-1,j) if i>0 and val<matrix[i-1][j] else 0,
                    dfs(i,j-1) if j>0 and val<matrix[i][j-1] else 0,
                    dfs(i+1,j) if i<m-1 and val<matrix[i+1][j] else 0,
                    dfs(i,j+1) if j<n-1 and val<matrix[i][j+1] else 0)
            return dp[i][j]
            
        if not matrix or not matrix[0]: return 0
        m, n=len(matrix), len(matrix[0])
        dp=[[0]*n for i in range(m)]
        return max(dfs(i,j) for i in range(m) for j in range(n))
        
