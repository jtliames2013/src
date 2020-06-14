class Solution:
    def minDays(self, bloomDay: List[int], m: int, k: int) -> int:
        def getCount(day):
            res, cnt, n=0, 0, len(bloomDay)
            for i in range(n):
                if bloomDay[i]>day: cnt=0
                else:
                    cnt+=1
                    if cnt==k:
                        res+=1
                        if res==m: return res
                        cnt=0
            return res
        
        if m*k>len(bloomDay): return -1
        l, r=1, 10**9
        while l<r:
            mid=l+(r-l)//2
            if getCount(mid)<m: l=mid+1
            else: r=mid
        return r

