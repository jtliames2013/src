class Solution:
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        area = 0
        l, r = 0, len(height)-1
        while l < r:
            h=min(height[l], height[r])
            area=max(area, h*(r-l))
            while (l<r and height[l]==h):
                l+=1
            while (l<r and height[r]==h):
                r-=1
        return area
