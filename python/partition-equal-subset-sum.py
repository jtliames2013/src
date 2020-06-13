class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        s=sum(nums)
        if s%2!=0: return False
        s//=2
        dp=[True]+[False]*s
        for n in nums:
            for i in range(s, n-1, -1):
                dp[i]=dp[i] or dp[i-n]
            if dp[s]==True: return True
        return dp[s]

