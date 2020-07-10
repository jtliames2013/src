class Solution:
    def numSubseq(self, nums: List[int], target: int) -> int:
        nums.sort()
        res, l, r, mod=0, 0, len(nums)-1, 10**9+7
        while l<=r:
            if nums[l]+nums[r]<=target:
                res+=pow(2, r-l, mod)
                l+=1
            else:
                r-=1
        
        return res%mod

