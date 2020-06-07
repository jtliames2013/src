class Solution:
    def minCost(self, houses: List[int], cost: List[List[int]], m: int, n: int, target: int) -> int:
        @lru_cache(None)
        def dfs(start, target, color):
            if start==m: return 0 if target==0 else float('inf')
            if target<0: return float('inf')
            
            if houses[start]==0:
                return min(cost[start][c-1]+dfs(start+1, target-(color!=c), c) for c in range(1, n+1))
            else:
                return dfs(start+1, target-(color!=houses[start]), houses[start])
        
        res=dfs(0, target, 0)
        return -1 if res==float('inf') else res

