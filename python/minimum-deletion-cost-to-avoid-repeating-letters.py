class Solution:
    def minCost(self, s: str, cost: List[int]) -> int:
        res, n=0, len(s)
        mx=0
        for i in range(n):
            if i>0 and s[i]!=s[i-1]:
                mx=0
            res+=min(cost[i], mx)
            mx=max(mx, cost[i])
        return res

