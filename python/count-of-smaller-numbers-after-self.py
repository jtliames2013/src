class Solution:
    def countSmaller(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        res=[0]*len(nums)
        sorted=[]
        
        for i in reversed(range(len(nums))):
            l, r=0, len(sorted)
            while l<r:
                mid=int(l+(r-l)/2)
                if sorted[mid]<nums[i]: l=mid+1
                else: r=mid
            res[i]=l
            sorted.insert(l, nums[i])
            
        return res
