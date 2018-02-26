class NumArray:

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.sums=[0]*(len(nums)+1)        
        for i in range(1, len(self.sums)):
            self.sums[i]=self.sums[i-1]+nums[i-1]

    def sumRange(self, i, j):
        """
        :type i: int
        :type j: int
        :rtype: int
        """
        return self.sums[j+1]-self.sums[i]        


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(i,j)
