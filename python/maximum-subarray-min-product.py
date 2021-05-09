class Solution:
    def maxSumMinProduct(self, nums: List[int]) -> int:
        mod=10**9+7
        res, n=0, len(nums)
        sums, left, right=[0]*(n+1), [0]*n, [0]*n
        for i in range(1, n+1):
            sums[i]=sums[i-1]+nums[i-1]

        stk=[]
        for i in range(n):
            while stk and nums[stk[-1]]>=nums[i]: stk.pop()
            if stk: left[i]=stk[-1]+1
            else: left[i]=0
            stk.append(i)

        stk=[]
        for i in range(n-1, -1, -1):
            while stk and nums[stk[-1]]>=nums[i]: stk.pop()
            if stk: right[i]=stk[-1]-1
            else: right[i]=n-1
            stk.append(i)

        for i in range(n):
            res=max(res, nums[i]*(sums[right[i]+1]-sums[left[i]]))
            
        return res%mod

