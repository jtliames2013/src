class Solution:
    def stoneGameVII(self, stones: List[int]) -> int:
        @lru_cache(None)
        def dfs(l, r):
            if l==r: return 0
            return max(sums[r+1]-sums[l+1]-dfs(l+1, r), sums[r]-sums[l]-dfs(l, r-1))
        n=len(stones)
        sums=[0]*(n+1)
        for i in range(1, n+1):
            sums[i]=sums[i-1]+stones[i-1]
        res=dfs(0, n-1)
        dfs.cache_clear()
        return res

