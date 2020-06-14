class Solution:
    def minDistance(self, houses: List[int], k: int) -> int:
        @lru_cache(None)
        def dfs(start, k):
            if start==n: return 0
            if k==0: return float('inf')
            res=float('inf')
            for i in range(start, n):
                res=min(res, costs[start][i]+dfs(i+1, k-1))
            return res
        
        n=len(houses)
        houses=sorted(houses)
        costs=[[0]*n for i in range(n)]
        for i in range(n):
            for j in range(i+1, n):
                m=(i+j)//2
                for h in range(i, j+1):
                    costs[i][j]+=abs(houses[h]-houses[m])
        return dfs(0, k)

