class Solution:
    def canBeIncreasing(self, nums: List[int]) -> bool:
        n=len(nums)
        prev, removed=nums[0], False
        for i in range(1, n):
            if nums[i]>prev:
                prev=nums[i]
            else:
                if removed: return False
                if i==1 or nums[i]>nums[i-2]:
                    prev=nums[i]
                removed=True
        return True

