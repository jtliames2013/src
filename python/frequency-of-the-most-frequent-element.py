class Solution:
    def maxFrequency(self, nums: List[int], k: int) -> int:
        l, n, sum, res=0, len(nums), 0, 0
        nums.sort()
        for r in range(n):
            sum+=nums[r]
            while k+sum<(r-l+1)*nums[r]:
                sum-=nums[l]
                l+=1
            res=max(res, r-l+1)
        return res

