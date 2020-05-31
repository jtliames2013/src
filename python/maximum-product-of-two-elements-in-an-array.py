class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        mx1, mx2=0, 0
        for _, v in enumerate(nums):
            if mx1<v:
                mx2=mx1
                mx1=v
            elif mx2<v:
                mx2=v
        return (mx1-1)*(mx2-1)

