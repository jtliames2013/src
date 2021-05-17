class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
        n, mask=len(nums), 0
        for i in nums:
            mask |= i
        return mask*pow(2, n-1)

