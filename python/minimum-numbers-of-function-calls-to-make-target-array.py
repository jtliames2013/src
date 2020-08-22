class Solution:
    def minOperations(self, nums: List[int]) -> int:
        res, n=0, len(nums)
        for i in range(32):
            zero, one=0, 0
            for j in range(n):
                if nums[j] & 1==1: one+=1                
                nums[j]>>=1
                if nums[j]==0: zero+=1
            res+=one
            if zero==n: break
            else: res+=1
        return res

