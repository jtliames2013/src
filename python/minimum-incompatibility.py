class Solution:
    def minimumIncompatibility(self, nums: List[int], k: int) -> int:
        @lru_cache(None)
        def dfs(nums):
            if not nums: return 0
            res=float('inf')
            st=set(nums)
            for c in combinations(st, m):
                remain=list(nums)        
                for i in c:
                    remain.remove(i)
                res=min(res, max(c)-min(c)+dfs(tuple(remain)))
            return res
        
        n=len(nums)
        m=n//k
        res=dfs(tuple(nums))
        return -1 if res==float('inf') else res

