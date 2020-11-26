class Solution:
    def waysToMakeFair(self, nums: List[int]) -> int:
        res, n=0, len(nums)
        left, right=[0, 0], [sum(nums[0::2]), sum(nums[1::2])]
        for i in range(n):
            right[i%2]-=nums[i]
            res+=left[0]+right[0]==left[1]+right[1]
            left[(i+1)%2]+=nums[i]
        return res

