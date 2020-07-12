class Solution:
    def minNumberOfSemesters(self, n: int, dependencies: List[List[int]], k: int) -> int:
        def countbit(n):
            res=0
            while n:
                n&=n-1
                res+=1
            return res
        
        m=1<<n
        dp, preq=[n]*m, [0]*n
        dp[0]=0
        for d in dependencies: preq[d[1]-1] |= 1<<(d[0]-1)
        for i in range(m):
            cand=0
            for j in range(n):
                if (i & preq[j]) == preq[j] and (i & (1<<j)) == 0: cand |= 1<<j
            c=cand
            while c>0:
                if countbit(c)<=k:
                    dp[i|c]=min(dp[i|c], dp[i]+1)
                c=(c-1)&cand
        return dp[-1]

