class Solution:
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        sorted=[]
        for num in nums:
            l, r=0, len(sorted)
            while l<r:
                mid=int(l+(r-l)/2)
                if sorted[mid]<num: l=mid+1
                else: r=mid
            if l==len(sorted): sorted.append(num)
            else: sorted[l]=num
        
        return len(sorted)
