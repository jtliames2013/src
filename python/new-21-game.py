class Solution:
    def new21Game(self, N, K, W):
        """
        :type N: int
        :type K: int
        :type W: int
        :rtype: float
        """
        if K==0 or N>=K+W: return 1
        dp=[1] + [0]*N
        s=1
        for i in range(1, N+1):
            dp[i]=s/W
            if i<K: s+=dp[i]
            if i-W>=0: s-=dp[i-W]
        return sum(dp[K:])
