class Solution:
    def countRoutes(self, locations: List[int], start: int, finish: int, fuel: int) -> int:
        @lru_cache(None)
        def dfs(start, finish, fuel):
            if abs(locations[start]-locations[finish])>fuel: return 0
            res=1 if start==finish else 0
            
            for i, v in enumerate(locations):
                if i==start: continue
                res+=dfs(i, finish, fuel-abs(v-locations[start]))
            return res
            
        mod=10**9+7
        return dfs(start, finish, fuel)%mod

