class Solution:
    def maxProductDifference(self, nums: List[int]) -> int:
        mx1, mx2, mn1, mn2=float('-inf'), float('-inf'), float('inf'), float('inf')
        for i in nums:
            if i>mx1:
                mx2=mx1
                mx1=i
            elif i>mx2:
                mx2=i
            if i<mn1:
                mn2=mn1
                mn1=i
            elif i<mn2:
                mn2=i
        return mx1*mx2-mn1*mn2

