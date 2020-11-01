class Solution:
    def bestTeamScore(self, scores: List[int], ages: List[int]) -> int:
        res, n=0, len(scores)
        players=list(zip(ages, scores))
        players.sort(key=lambda i: (-i[0], -i[1]))
        dp=[0]*n
        for i in range(n):
            dp[i]=players[i][1]
            for j in range(i):
                if players[j][1]>=players[i][1]:
                    dp[i]=max(dp[i], dp[j]+players[i][1])
            res=max(res, dp[i])
        return res

