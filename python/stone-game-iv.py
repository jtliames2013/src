class Solution:
    def winnerSquareGame(self, n: int) -> bool:
        dp=[False]*(n+1)
        for i in range(1, n+1):
            dp[i]=not all(dp[i-j*j] for j in range(1, int(sqrt(i))+1))
        return dp[-1]

