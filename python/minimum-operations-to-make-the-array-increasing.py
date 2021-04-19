class Solution:
    def minOperations(self, nums: List[int]) -> int:
        res, prev=0, 0
        for i in nums:
            res+=max(0, prev-i+1)
            prev=max(prev+1, i)
        return res

