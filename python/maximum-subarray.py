class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        local, res=0, float('-inf')
        for i in nums:
            local+=i
            res=max(res, local)
            if local<0: local=0
        return res

