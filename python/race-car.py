class Solution:
    def racecar(self, target):
        """
        :type target: int
        :rtype: int
        """
        def dfs(dist):
            if dp[dist]>0: return dp[dist]
            n=dist.bit_length()
            if (1<<n)==dist+1: dp[dist]=n
            else:
                dp[dist]=dfs((1<<n)-1-dist)+n+1
                for i in range(n-1):
                    dp[dist]=min(dp[dist], dfs(dist-(1<<(n-1))+(1<<i))+n+i+1)
            return dp[dist]
        
        dp=[0]*(target+1)
        return dfs(target)
