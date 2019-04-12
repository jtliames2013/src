class Solution:
    def stoneGame(self, piles: List[int]) -> bool:
        n=len(piles)
        dp=piles[:]
        for l in range(1,n):
            for i in range(n-l):
                dp[i]=max(piles[i]-dp[i+1], piles[i+l]-dp[i])
        return dp[0]>0
