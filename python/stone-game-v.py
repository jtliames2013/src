class Solution:
    def stoneGameV(self, stoneValue: List[int]) -> int:
        @lru_cache(None)
        def dfs(start, end):
            if start==end: return 0
            res=float('-inf')
            for i in range(start, end):
                l, r=sums[i+1]-sums[start], sums[end+1]-sums[i+1]
                if l<r: res=max(res, l+dfs(start, i))
                elif l>r: res=max(res, r+dfs(i+1, end))
                else:
                    res=max(res, l+dfs(start, i), l+dfs(i+1, end))
            return res
        
        n=len(stoneValue)
        sums=[0]*(n+1)
        for i, v in enumerate(stoneValue):
            sums[i+1]=sums[i]+v
        return dfs(0, n-1)
