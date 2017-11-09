class Solution:
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        res, left, right = 0, 0, len(height)-1
        maxLeft, maxRight = 0, 0
        while left<right:
            if height[left]<height[right]:
                if maxLeft<=height[left]:
                    maxLeft=height[left]                    
                else:
                    res+=maxLeft-height[left]
                left+=1
            else:
                if maxRight<=height[right]:
                    maxRight=height[right]
                else:
                    res+=maxRight-height[right]
                right-=1
        return res
