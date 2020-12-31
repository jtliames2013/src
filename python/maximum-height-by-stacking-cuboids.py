class Solution:
    def maxHeight(self, cuboids: List[List[int]]) -> int:
        res=0
        for c in cuboids: c.sort()
        cuboids=[[0, 0, 0]] + sorted(cuboids)
        n=len(cuboids)
        dp=[0]*n
        
        for i in range(1, n):
            for j in range(i):
                if cuboids[i][0]>=cuboids[j][0] and cuboids[i][1]>=cuboids[j][1] and cuboids[i][2]>=cuboids[j][2]:
                    dp[i]=max(dp[i], dp[j]+cuboids[i][2])
            res=max(res, dp[i])    
        return res

