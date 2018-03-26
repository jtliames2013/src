class Solution:
    def numSubarrayProductLessThanK(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        if k<=1: return 0
        res=0
        l, r, n, prod=0, 0, len(nums), 1
        while r<n:
            prod*=nums[r]
            while prod>=k:
                prod/=nums[l]
                l+=1
            res+=r-l+1
            r+=1
        return res
