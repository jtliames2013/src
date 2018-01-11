class Solution:
    def findTargetSumWays(self, nums, S):
        """
        :type nums: List[int]
        :type S: int
        :rtype: int
        """
        sum=0
        for n in nums: sum+=n
        if sum<abs(S) or (sum+S)%2!=0: return 0
        
        target=int((sum+S)/2)
        dp=[1]+[0]*target
        for n in nums:
            for i in range(target, n-1, -1):
                dp[i]+=dp[i-n]
        
        return dp[target]

