class Solution:
    def constrainedSubsetSum(self, nums: List[int], k: int) -> int:
        dp=[]
        dq=collections.deque()
        
        for i in range(len(nums)):
            dp += (max(dp[dq[0]], 0) if dq else 0) + nums[i],            
            while dq and dp[dq[-1]]<dp[-1]: dq.pop()
            dq += i,
            if i-dq[0]>=k: dq.popleft()
        return max(dp)

