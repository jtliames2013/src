class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:
        n=len(nums)
        res, mod, s=n, sum(nums)%p, 0
        d=collections.defaultdict(int)
        d[0]=-1
        if mod==0: return 0
        
        for i, v in enumerate(nums):
            s=(s+v)%p
            pre=(s+p-mod)%p
            if pre in d:
                res=min(res, i-d[pre])
            d[s]=i
        
        return -1 if res==n else res
            
