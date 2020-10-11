1.
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        if not nums: return 0
        res, n=float('-inf'), len(nums)
        dp=[1]*n
        for i in range(n):
            for j in range(i):
                if nums[i]>nums[j]: dp[i]=max(dp[i], dp[j]+1)
            res=max(res, dp[i])
        return res

2.
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        sorted=[]
        for num in nums:
            l, r=0, len(sorted)
            while l<r:
                mid=(l+r)//2
                if sorted[mid]<num: l=mid+1
                else: r=mid
            if l==len(sorted): sorted.append(num)
            else: sorted[l]=num

        return len(sorted)

3.
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        sorted=[]
        for n in nums:
            pos=bisect.bisect_left(sorted, n)
            if pos==len(sorted): sorted.append(n)
            else: sorted[pos]=n
        return len(sorted)

