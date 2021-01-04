class Solution:
    def waysToSplit(self, nums: List[int]) -> int:
        mod=10**9+7
        res, n=0, len(nums)
        for i in range(1, n):
            nums[i]+=nums[i-1]
        for i in range(n-2):
            j=bisect_left(nums, nums[i]*2, i+1)
            if j<n:
                k=bisect_right(nums, (nums[i]+nums[-1])//2, j, n-1)
                if k>j:
                    res=(res+(k-j))%mod
        return res

