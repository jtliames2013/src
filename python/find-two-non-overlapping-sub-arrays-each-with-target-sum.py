class Solution:
    def minSumOfLengths(self, arr: List[int], target: int) -> int:
        d={0: -1}
        s, end, res, mn, prev=0, -1, float('inf'), float('inf'), 0
        for i, v in enumerate(arr):
            s+=v
            if s-target in d:
                j=d[s-target]
                l=i-j
                if j>=end or l<prev: 
                    end=i
                    res=min(res, mn+l)
                    mn=min(mn, l)
                    prev=l
            d[s]=i
        return -1 if res==float('inf') else res

