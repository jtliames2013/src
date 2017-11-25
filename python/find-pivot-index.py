class Solution(object):
    def pivotIndex(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        left, right = 0, sum(nums)
        for i, n in enumerate(nums):
            right-=n
            if left==right:
                return i
            left+=n
        return -1

