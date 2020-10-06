class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp=[1]+[0]*(n-1)
        for i in range(m):
            for j in range(n):
                if j>0: dp[j]+=dp[j-1]
        return dp[-1]

