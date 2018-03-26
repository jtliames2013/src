class Solution:
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        l, r=0, len(nums)
        while l<r:
            mid=int(l+(r-l)/2)
            if nums[mid]<target: l=mid+1
            else: r=mid
        return r
