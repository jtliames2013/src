class Solution:
    def longestAwesome(self, s: str) -> int:
        res, n, mask=0, len(s), 0
        dp=[n]*2014
        dp[0]=-1
        for i, c in enumerate(s):
            mask^=(1<<int(c))
            res=max(res, i-dp[mask])
            for j in range(10):
                res=max(res, i-dp[mask^(1<<j)])
            dp[mask]=min(dp[mask], i)
        return res

