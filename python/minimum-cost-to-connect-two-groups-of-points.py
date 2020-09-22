class Solution:
    def connectTwoGroups(self, cost: List[List[int]]) -> int:
        @lru_cache(None)
        def dfs(start, mask):
            if start==m:
                res=0
                for i in range(n):
                    if (mask & (1<<i))==0:
                        res+=mn[i]
                return res
            
            res=float('inf')
            for i in range(n):
                res=min(res, cost[start][i]+dfs(start+1, mask | (1<<i)))
            return res
        
        m, n=len(cost), len(cost[0])
        mn=[min([cost[i][j] for i in range(m)]) for j in range(n)]
        return dfs(0, 0)

