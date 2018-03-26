class Solution:
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        local, res=0, -sys.maxsize
        for i in nums:
            local+=i;
            res=max(res, local)
            if local<0: local=0
        return res
