class Solution:
    def countNicePairs(self, nums: List[int]) -> int:
        def rev(n):
            res=0
            while n:
                res=res*10+n%10
                n//=10
            return res
        
        mod=10**9+7
        res, cnt=0, defaultdict(int)
        for n in nums:
            n-=rev(n)
            res+=cnt[n]
            cnt[n]+=1
        return res%mod

