class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        res, l, k=0, 0, 1
        for r in range(len(nums)):
            if nums[r]==0: k-=1
            while k<0:
                if nums[l]==0: k+=1
                l+=1
            res=max(res, r-l)
        return res

