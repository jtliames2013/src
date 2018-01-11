class Solution:
    def combinationSum4(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        dp=[1]+[0]*target
        nums.sort()
        for i in range(1, target+1):
            for n in nums:
                if i<n: break
                dp[i]+=dp[i-n]
        
        return dp[target]
