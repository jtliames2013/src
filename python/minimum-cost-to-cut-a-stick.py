class Solution:
    def minCost(self, n: int, cuts: List[int]) -> int:
        @lru_cache(None)
        def dfs(start, end):
            if start>=end: return 0
            res=float('inf')
            for i in range(len(cuts)):
                if start<=cuts[i]<=end:
                    tmp=cuts[i]
                    cuts[i]=-1
                    cost=end-start+dfs(start, tmp)+dfs(tmp, end)
                    cuts[i]=tmp
                    res=min(res, cost)
            if res==float('inf'): res=0
            return res
        return dfs(0, n)

