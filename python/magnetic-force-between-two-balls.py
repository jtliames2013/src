class Solution:
    def maxDistance(self, position: List[int], m: int) -> int:
        def count(d):
            res, prev=1, 0
            for i in range(1, n):
                if position[i]-position[prev]>=d:
                    prev=i
                    res+=1
            return res
        
        n=len(position)
        position.sort()
        l, r=1, position[-1]-position[0]
        while l<r:
            mid=(l+r)//2+1
            if count(mid)<m: r=mid-1
            else: l=mid
        return l

