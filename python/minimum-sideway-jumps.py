class Solution:
    def minSideJumps(self, obstacles: List[int]) -> int:
        n, dp=len(obstacles), [1, 0, 1]
        for o in obstacles:
            next=[float('inf')]*3
            if o!=0: dp[o-1]=float('inf')
            for j in range(3):
                if o!=j+1: next[j]=min(dp[j], dp[(j+1)%3]+1, dp[(j+2)%3]+1)
            dp=next.copy()
        return min(dp)

