class Solution:
    def getMaxGridHappiness(self, m: int, n: int, introvertsCount: int, extrovertsCount: int) -> int:
        def getCost(row, col, inMask, exMask, delta):
            res=0
            if col>0:
                if (inMask & 1): res+=delta-30
                if (exMask & 1): res+=delta+20
            if row>0:
                if (inMask & (1<<(n-1))): res+=delta-30
                if (exMask & (1<<(n-1))): res+=delta+20
            return res
            
        @lru_cache(None)
        def dfs(pos, inCnt, exCnt, inMask, exMask):
            row, col=pos/n, pos%n
            if row==m: return 0
            nextInMask, nextExMask=(inMask<<1) & mask, (exMask<<1) & mask
            
            res=dfs(pos+1, inCnt, exCnt, nextInMask, nextExMask)
            if inCnt>0:
                cost=120+getCost(row, col, inMask, exMask, -30)
                res=max(res, cost+dfs(pos+1, inCnt-1, exCnt, nextInMask | 1, nextExMask))
            if exCnt>0:
                cost=40+getCost(row, col, inMask, exMask, 20)
                res=max(res, cost+dfs(pos+1, inCnt, exCnt-1, nextInMask, nextExMask | 1))
                
            return res
            
        mask=(1<<n)-1
        return dfs(0, introvertsCount, extrovertsCount, 0, 0)

