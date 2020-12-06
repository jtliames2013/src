class Solution:
    def minimumMountainRemovals(self, nums: List[int]) -> int:
        res, n=float('-inf'), len(nums)
        sorted, dp=[], [0]*n
        for i in range(n):
            pos=bisect_left(sorted, nums[i])
            if pos==len(sorted): sorted.append(nums[i])
            else: sorted[pos]=nums[i]
            dp[i]=len(sorted)
        sorted=[]
        for i in range(n-1, 0, -1):
            pos=bisect_left(sorted, nums[i])
            if pos==len(sorted): sorted.append(nums[i])
            else: sorted[pos]=nums[i]
            if dp[i]>1 and len(sorted)>1: res=max(res, dp[i]+len(sorted)-1)
        return n-res

