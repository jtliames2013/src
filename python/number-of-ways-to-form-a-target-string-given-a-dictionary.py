class Solution:
    def numWays(self, words: List[str], target: str) -> int:
        @lru_cache(None)
        def dfs(col, start):
            if start==n: return 1
            if col==m: return 0
            res=dfs(col+1, start)
            if count[ord(target[start])][col]>0:
                res=(res+dfs(col+1, start+1)*count[ord(target[start])][col])%mod
            return res
            
        mod=10**9+7
        m, n=len(words[0]), len(target)
        count=[[0]*m for _ in range(128)]
        for w in words:
            for i in range(m):
                count[ord(w[i])][i]+=1
        return dfs(0, 0)

