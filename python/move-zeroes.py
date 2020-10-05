class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n, end=len(nums), 0
        for i in range(n):
            if nums[i]!=0:
                if end!=i:
                    nums[end], nums[i]=nums[i], nums[end]
                end+=1

