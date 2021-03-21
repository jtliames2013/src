class Solution:
    def maxAscendingSum(self, nums: List[int]) -> int:
        res, sum, n=nums[0], nums[0], len(nums)
        for i in range(1, n):
            if nums[i]<=nums[i-1]:
                sum=0
            sum+=nums[i]
            res=max(res, sum)
        return res
        
