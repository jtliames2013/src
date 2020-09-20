class Solution:
    def maxSumRangeQuery(self, nums: List[int], requests: List[List[int]]) -> int:
        mod=10**9+7
        n=len(nums)
        cnt=[0]*(n+1)
        for r in requests:
            cnt[r[0]]+=1
            cnt[r[1]+1]-=1
        cnt.pop()
        for i in range(1, n): cnt[i]+=cnt[i-1]
        
        res=0
        for c, v in zip(sorted(cnt), sorted(nums)):
            res+=c*v
        return res%mod

