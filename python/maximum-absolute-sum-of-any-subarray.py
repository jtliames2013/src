1.
class Solution:
    def maxAbsoluteSum(self, nums: List[int]) -> int:
        mn=mx=sum=0
        n=len(nums)
        for i in range(n):
            sum+=nums[i]
            mn=min(mn, sum)
            mx=max(mx, sum)
        return mx-mn

2.
class Solution:
    def maxAbsoluteSum(self, nums: List[int]) -> int:
        return max(accumulate(nums, initial=0)) - min(accumulate(nums, initial=0))
