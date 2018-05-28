class Solution:
    def largestSumOfAverages(self, A, K):
        """
        :type A: List[int]
        :type K: int
        :rtype: float
        """
        dp={}
        for i in range(len(A)):
            dp[1,i+1]=sum(A[:i+1])/float(i+1)

        def dfs(n, k):
            if n<k: return 0
            if (k,n) in dp: return dp[k,n]
            s, dp[k,n]=0, 0
            for i in range(n-1, 0, -1):
                s+=A[i]
                dp[k,n]=max(dp[k,n], dfs(i,k-1)+s/float(n-i))
            return dp[k,n]
        
        return dfs(len(A), K)
