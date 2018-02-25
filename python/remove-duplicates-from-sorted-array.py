class Solution:
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        end=0
        for i in range(len(nums)):
            if i==0 or nums[i]!=nums[i-1]:
                if i!=end: nums[end]=nums[i]
                end+=1
        return end
