class Solution:
    def rangeSum(self, nums: List[int], n: int, left: int, right: int) -> int:
        res, mod=0, 10**9+7
        pq=[]
        for i, v in enumerate(nums): heappush(pq, (v, i+1))
        for i in range(1, right+1):
            v, j=heappop(pq)
            if i>=left: res=(res+v)%mod
            if j<n: heappush(pq, (v+nums[j], j+1))
        return res

