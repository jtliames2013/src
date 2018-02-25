class Solution:
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        i=len(nums)-1
        while i>0:
            if nums[i]>nums[i-1]: break
            i-=1
        
        if i==0:
            nums.reverse()
            return
        
        k=i-1
        j=len(nums)-1
        while j>=i:
            if nums[j]>nums[k]: break
            j-=1
        nums[k], nums[j]=nums[j], nums[k]
        nums[i:]=reversed(nums[i:])
