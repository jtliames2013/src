class Solution:
    def maxProductPath(self, grid: List[List[int]]) -> int:
        mod=10**9+7
        m, n=len(grid), len(grid[0])
        dp=[[[1, 1] for j in range(n)] for i in range(m)]
        for i in range(0, m):
            for j in range(0, n):
                if i==0 and j==0:
                    dp[i][j][0]=dp[i][j][1]=grid[i][j]
                elif i==0:
                    dp[i][j][0]=dp[i][j][1]=grid[i][j]*dp[i][j-1][0]
                elif j==0:
                    dp[i][j][0]=dp[i][j][1]=grid[i][j]*dp[i-1][j][0]
                else:
                    mx=max(dp[i-1][j][0], dp[i][j-1][0])*grid[i][j]
                    mn=min(dp[i-1][j][1], dp[i][j-1][1])*grid[i][j]
                    dp[i][j][0]=max(mx, mn)
                    dp[i][j][1]=min(mx, mn)
                      
        return dp[m-1][n-1][0]%mod if dp[m-1][n-1][0]>=0 else -1

