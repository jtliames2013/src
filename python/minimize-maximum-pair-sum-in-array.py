class Solution:
    def minPairSum(self, nums: List[int]) -> int:
        return max(a+b for a, b in zip(sorted(nums), sorted(nums)[::-1]))

