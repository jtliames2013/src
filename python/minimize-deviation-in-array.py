class Solution:
    def minimumDeviation(self, nums: List[int]) -> int:
        res, mn, pq=float('inf'), float('inf'), []
        for n in nums:
            top=2*n if n%2==1 else n
            heappush(pq, -top)
            mn=min(mn, top)
            
        while True:
            t=-heappop(pq)
            res=min(res, t-mn)
            if t%2==1: break
            mn=min(mn, t//2)
            heappush(pq, -t//2)    
        return res

